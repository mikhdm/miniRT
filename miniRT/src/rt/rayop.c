/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayop.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:26:17 by rmander           #+#    #+#             */
/*   Updated: 2021/04/30 04:27:24 by rmander          ###   ########.fr       */
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

int	ft_trace_plane(t_data *data, t_vector3 *dirvec, t_pair_double *steprange)
{
	double			closest_step;
	t_vector3		closest_point;
	t_vector3		cmult_dirvec;
	double			step;
	short int		intersected;
	int				color;

	closest_step = INFINITY;
	intersected = FALSE;
	step = ft_intersect_plane(data, dirvec, data->figures->plane);
	if (step >= steprange->first && step <= steprange->second
		&& step < closest_step)
	{
		closest_step = step;
		intersected = TRUE;
	}
	if (intersected == FALSE)
		return (0x0);
	
	color = data->figures->plane->color;
	cmult_dirvec = cmultvec3(closest_step, dirvec);
	closest_point = sumvec3(&data->cam->center, &cmult_dirvec);

	/* disk condition */
	/* t_vector3 plane_vec = diffvec3(&closest_point, &data->figures->plane->center); */
	/* double plane_vec_length = hypotvec3(&plane_vec); */
	/* double radius = 0.6; */
	/* if (plane_vec_length > radius * radius) */
	/* 	return (0x0); */

	/* square condition */
	/* t_vector3 plane_vec = diffvec3(&closest_point, &data->figures->plane->center); */
	/* double plane_vec_length = hypotvec3(&plane_vec); */
	/* double side = 12.0; */
	/* if (plane_vec_length*(side/2) > pow(2, 0.5) * side) */
	/* 	return (0x0); */

	color = light(data, &closest_point, &data->figures->plane->orient, color);
	return (color);
}

int	ft_trace_sphere(t_data *data, t_vector3 *dirvec, t_pair_double *steprange)
{
	double 			closest_step;
	short int		intersected;
	t_vector3		closest_point;
	t_vector3		orient;
	t_pair_double	steps;
	t_vector3		cmult_dirvec;

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

	int color = data->figures->sphere->color;
	color = light(data, &closest_point, &orient, color);
	return (color);
}
