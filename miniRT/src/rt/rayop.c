/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayop.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:26:17 by rmander           #+#    #+#             */
/*   Updated: 2021/05/05 14:18:05 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "linop.h"
#include "light.h"
#include "utils.h"
#include "libft.h"
#include "color.h"
#include <math.h>

#include <stdio.h>

/* double			ft_intersect_triangle(t_data *data, */
/* 					t_vector3 *dirvec, t_triangle *triangle) */
/* { */
/* } */

double			ft_intersect_plane(t_data *data,
					t_vector3 *dirvec, t_plane *plane)
{
	t_vector3	pl_cam_vec;
	double		denominator;
	double		step;

	step = INFINITY;
	pl_cam_vec = diffvec3(&plane->center, &data->cam->center);
	denominator = dot3(dirvec, &plane->orient);
	if (denominator > 1e-6)
		step = dot3(&pl_cam_vec, &plane->orient) / denominator;
	return (step);
}

double			ft_intersect_square(t_data *data,
					t_vector3 *dirvec, t_square *square)
{
	/* TODO generalize intersection with plane and square */
	t_vector3	pl_cam_vec;
	double		denominator;
	double		step;

	step = INFINITY;
	pl_cam_vec = diffvec3(&square->center, &data->cam->center);
	denominator = dot3(dirvec, &square->orient);
	if (denominator > 1e-6)
		step = dot3(&pl_cam_vec, &square->orient) / denominator;
	return (step);
}

t_pair_double	ft_intersect_sphere(t_data *data, t_vector3 *dirvec, t_sphere *sphere)
{
	double			radius;
	t_vector3		sp_cam_vec;
	t_pair_double	values;
	
	radius = sphere->diameter / 2;
	// TODO try normalize sp_cam_vec
	sp_cam_vec = diffvec3(&data->cam->center, &sphere->center);

	values = calc_quad_equation(
			dot3(dirvec, dirvec),
			2 * dot3(dirvec, &sp_cam_vec),
			dot3(&sp_cam_vec, &sp_cam_vec) - pow(radius, 2));
	return (values);
}

/*
*
* _trace_plane - calculates t (closest_step) param of hit point.
*	first -> t value, second - intersected or not;
*
*/
static t_pair_double_int	_trace_plane(t_data *data, t_vector3 *dirvec, t_pair_double *steprange)
{
	t_pair_double_int	pair;
	double				step;

	pair.first = INFINITY;
	pair.second = FALSE;
	step = ft_intersect_plane(data, dirvec, data->figures->plane);
	if (step >= steprange->first && step <= steprange->second && step < pair.first)
	{
		pair.first = step;
		pair.second = TRUE;
	}
	return (pair);
}

int	ft_trace_plane(t_data *data, t_vector3 *dirvec, t_pair_double *steprange)
{
	t_vector3			closest_point;
	t_vector3			t_mult_dirvec;
	int					color;
	t_pair_double_int	pair;

	color = data->figures->plane->color;
	pair = _trace_plane(data, dirvec, steprange);
	if (!pair.second)
		return (COLOR_BACKGROUND);
	t_mult_dirvec = cmultvec3(pair.first, dirvec);
	closest_point = sumvec3(&data->cam->center, &t_mult_dirvec);
	color = light(data, &closest_point, &data->figures->plane->orient, color);
	return (color);
}

static t_pair_double_int	_trace_square(t_data *data, t_vector3 *dirvec, t_pair_double *steprange)
{
	t_pair_double_int	pair;
	double				step;

	pair.first = INFINITY;
	pair.second = FALSE;
	step = ft_intersect_square(data, dirvec, data->figures->square);
	if (step >= steprange->first && step <= steprange->second && step < pair.first)
	{
		pair.first = step;
		pair.second = TRUE;
	}
	return (pair);
}

int	ft_trace_square(t_data *data, t_vector3 *dirvec, t_pair_double *steprange)
{
	t_vector3			closest_point;
	t_vector3			t_mult_dirvec;
	int					color;
	t_vector3			orient;
	double				size;
	t_pair_double_int	pair;

	color = data->figures->square->color;
	orient = data->figures->square->orient;
	size = data->figures->square->size;
	pair = _trace_square(data, dirvec, steprange);
	if (!pair.second)
		return (COLOR_BACKGROUND);
	t_mult_dirvec = cmultvec3(pair.first, dirvec);
	closest_point = sumvec3(&data->cam->center, &t_mult_dirvec);
	
	/* TODO add hit square point detection */

	t_vector3	rand_vec;
	t_vector3	sq_vec[4];
	t_vector3	vertices[4];
	size_t		i;

	rand_vec = (t_vector3) {.x = 1000, .y = 0, .z = 0};
	if (iscollinvec3(&rand_vec, &orient)) 
		rand_vec = (t_vector3) {.x = 0, .y = 1000, .z = 0};

	sq_vec[0] = cross3(&rand_vec, &orient);
	sq_vec[1] = cross3(&sq_vec[0], &orient);

	sq_vec[0] = normvec3(&sq_vec[0]);
	sq_vec[1] = normvec3(&sq_vec[1]);
	sq_vec[2] = cmultvec3(-1.0, &sq_vec[0]);
	sq_vec[3] = cmultvec3(-1.0, &sq_vec[1]);

	i = 0;
	while (i < 4)
	{
		sq_vec[i] = cmultvec3(size, &sq_vec[i]);
		/* this is not sum of vectors, but sum of vector with point */
		/* due to the fact we have P1 - P0 + P0 = P1 -- the top-left vertex of square etc. */
		vertices[i] = sumvec3(&sq_vec[i], &data->figures->square->center);
		++i;
	}

	/* double	lcheck; */
	/* double	rcheck; */

	/* t_vector3	hitp1vec = diffvec3(&closest_point, &vertices[0]); */
	/* t_vector3	p1p2vec = diffvec3(&vertices[1], &vertices[0]); */
	/* t_vector3	p2p3vec = diffvec3(&vertices[2], &vertices[1]); */

	/* lcheck = dot3(&hitp1vec, &p1p2vec) / size; */
	/* rcheck = dot3(&hitp1vec, &p2p3vec) / size; */
	/* if (lcheck >= 0 && lcheck <= 1 && rcheck >= 0 && rcheck <= 1) */
	/* { */
	/* 	printf("lcheck: %f, rcheck: %f\n", lcheck, rcheck); */
	/* } */	
	color = light(data, &closest_point, &orient, color);
	return (color);
	/* return (COLOR_BACKGROUND); */
}

int	ft_trace_sphere(t_data *data, t_vector3 *dirvec, t_pair_double *steprange)
{
	double 			closest_step;
	short int		intersected;
	t_vector3		closest_point;
	t_vector3		orient;
	t_pair_double	steps;
	t_vector3		cmult_dirvec;
	int				color;

	closest_step = INFINITY;
	intersected = FALSE;
	steps = ft_intersect_sphere(data, dirvec, data->figures->sphere);
	if (steps.first >= steprange->first && steps.first <= steprange->second
		&& steps.first < closest_step)
	{
		closest_step = steps.first;
		intersected = TRUE;
	}
	if (steps.second >= steprange->first && steps.second <= steprange->second
		&& steps.second < closest_step)
	{
		closest_step = steps.second;
		intersected = TRUE;
	}
	if (intersected == FALSE)
		return (0x0);
	
	cmult_dirvec = cmultvec3(closest_step, dirvec);
	closest_point = sumvec3(&data->cam->center, &cmult_dirvec);
	orient = calc_sphere_orient(&closest_point, data->figures->sphere);

	color = data->figures->sphere->color;
	color = light(data, &closest_point, &orient, color);
	return (color);
}
