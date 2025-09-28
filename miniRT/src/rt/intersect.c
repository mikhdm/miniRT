/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 23:28:15 by rmander           #+#    #+#             */
/*   Updated: 2021/05/09 19:32:18 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "linop.h"
#include "utils.h"
#include <math.h>

double			intersect_plane(t_data *data,
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

double			intersect_square(t_data *data,
					t_vector3 *dirvec, t_square *square)
{
	t_vector3	pl_cam_vec;
	t_vector3	orient;
	double		denominator;
	double		step;

	step = INFINITY;
	orient = square->orient;
	denominator = dot3(dirvec, &orient);
	if (denominator < 0.0) 
	{
		orient = cmultvec3(-1, &orient);
		denominator = -denominator;
	}
	pl_cam_vec = diffvec3(&square->center, &data->cam->center);
	if (denominator > 1e-6)
		step = dot3(&pl_cam_vec, &orient) / denominator;
	return (step);
}

double			intersect_triangle(t_data *data,
					t_vector3 *dirvec, t_triangle *triangle)
{
	/* TODO */
	(void)data;
	(void)dirvec;
	(void)triangle;
	return (1);
}

double	intersect_sphere(t_data *data,
					t_vector3 *dirvec, t_sphere *sphere)
{
	double			radius;
	t_vector3		sp_cam_vec;
	t_pair_double	values;
	
	t = INFINITY;
	radius = sphere->diameter / 2;
	sp_cam_vec = diffvec3(&data->cam->center, &sphere->center);
	values = calc_quad_equation(
			dot3(dirvec, dirvec),
			2 * dot3(dirvec, &sp_cam_vec),
			dot3(&sp_cam_vec, &sp_cam_vec) - pow(radius, 2));
	t = fmin(values.first, values.second);
	if (values.first > values.second)
		ft_swap_double(&values.first, &values.second);
	if (values.first < 0)
		values.first = values.second;
		if (values.first < 0)
			return (INFINITY);
	return (values.first);
}				

double	intersect_cylinder(t_data *data,
			t_vector3	*dirvec, t_cylinder *cylinder)
{
	/* TODO */
	(void)data;
	(void)dirvec;
	(void)cylinder;
	return (1);
}
