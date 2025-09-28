/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 23:28:15 by rmander           #+#    #+#             */
/*   Updated: 2021/05/14 21:05:01 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "linop.h"
#include "utils.h"
#include <math.h>
#include <stdio.h>

double			intersect_plane(t_data *data,
						 t_vector3 *dirvec, t_plane *plane)
{
	t_vector3	pl_cam_vec;
	double		denominator;
	double		t;

	t = INFINITY;
	pl_cam_vec = diffvec3(&plane->center, &data->cam->center);
	denominator = dot3(dirvec, &plane->orient);
	if (denominator > 1e-6)
		t = dot3(&pl_cam_vec, &plane->orient) / denominator;
	return (t);
}

double			intersect_square(t_data *data,
						  t_vector3 *dirvec, t_square *square)
{
	t_vector3	pl_cam_vec;
	t_vector3	orient;
	double		denominator;
	double		t;

	t = INFINITY;
	orient = square->orient;
	denominator = dot3(dirvec, &orient);
	/* TODO maybe not */
	if (denominator < 0.0)
	{
		orient = cmultvec3(-1, &orient);
		denominator = -denominator;
	}
	pl_cam_vec = diffvec3(&square->center, &data->cam->center);
	if (denominator > 1e-6)
		t = dot3(&pl_cam_vec, &orient) / denominator;
	return (t);
}

double			intersect_triangle(t_data *data,
							t_vector3 *dirvec, t_triangle *triangle)
{
	t_vector3   orient;
	t_vector3	pl_cam_vec;
	double		denominator;
	double		t;

	pl_cam_vec = diffvec3(&triangle->x, &data->cam->center);
	orient = calc_triangle_orient(triangle);
	t = INFINITY;
	denominator = dot3(dirvec, &orient);
	/* TODO maybe not */
	if (denominator < 0.0)
	{
		orient = cmultvec3(-1, &orient);
		denominator = -denominator;
	}
	if (denominator > 1e-6)
		t = dot3(&pl_cam_vec, &orient) / denominator;
	return (t);
}

 double	intersect_sphere(t_data *data,
						t_vector3 *dirvec, t_sphere *sphere)
{
	double			radius;
	t_vector3		co;
	t_pair_double	values;
	
	radius = sphere->diameter / 2;
	co = diffvec3(&data->cam->center, &sphere->center);
	values = calc_quad_equation(
			dot3(dirvec, dirvec),
			2 * dot3(dirvec, &co),
			dot3(&co, &co) - pow(radius, 2));
	return (calc_min_t(values));
}

double  intersect_cylinder(t_data *data,
						  t_vector3 *dirvec, t_cylinder *cylinder)
{
	double          radius;
	t_vector3       co;
	t_pair_double   values_t;

	radius = cylinder->diameter / 2;
	co = diffvec3(&data->cam->center, &cylinder->center);
	values_t = calc_quad_equation(
	dot3(dirvec, dirvec) - pow(dot3(&cylinder->orient, dirvec), 2.0),
	2 * (dot3(&co, dirvec) -
			dot3(dirvec, &cylinder->orient) * dot3(&co, &cylinder->orient)),
	dot3(&co, &co) - pow(dot3(&co, &cylinder->orient), 2.0) - pow(radius, 2.0));
	return (calc_cylinder_min_t(data, &values_t, dirvec, cylinder));
}