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
#include <stdio.h>
#include <math.h>
#include <errno.h>

double  intersect_plane(t_vector3 *p0, t_vector3 *dirvec, t_plane *plane)
{
	t_vector3	co;
	double		denom;
	double		t;

	t = INFINITY;
	co = diffvec3(&plane->center, p0);
	denom = dot3(dirvec, &plane->orient);
	if (fabs(denom) > 1e-6)
		t = dot3(&co, &plane->orient) / denom;
	return (t);
}

double  intersect_square(t_vector3 *p0, t_vector3 *dirvec, t_square *square)
{
	t_vector3	co;
	double		denom;
	double		t;
	t_vector3	*vertices;
	t_vector3	p_hit;

	t = INFINITY;
	denom = dot3(dirvec, &square->orient);
	co = diffvec3(&square->center, p0);
	if (fabs(denom) > 1e-6)
		t = dot3(&co, &square->orient) / denom;

	p_hit = calc_ray_point(p0, dirvec, t);
	vertices = gen_square_vertices(square);
	if (!vertices)
		exit(ENOMEM);
	if (is_polygon_point(&p_hit, vertices, &square->orient, 4))
		return (t);
	return (INFINITY);
}

double  intersect_triangle(t_vector3 *p0, t_vector3 *dirvec, t_triangle *triangle)
{
	t_vector3   orient;
	t_vector3	co;
	double		denom;
	double		t;

	t = INFINITY;
	orient = calc_triangle_orient(triangle);
	denom = dot3(dirvec, &orient);
	co = diffvec3(&triangle->x, p0);
	if (fabs(denom) > 1e-6)
		t = dot3(&co, &orient) / denom;

	t_vector3   vertices[3];
	t_vector3   p_hit;
	vertices[0] = triangle->x;
	vertices[1] = triangle->y;
	vertices[2] = triangle->z;
	if (!isinf(t))
	{
		p_hit = calc_ray_point(p0, dirvec, t);
		if (is_polygon_point(&p_hit, vertices, &orient, 3))
			return (t);
	}
	return (INFINITY);
}

 double intersect_sphere(t_vector3 *p0, t_vector3 *dirvec, t_sphere *sphere)
{
	double			radius;
	t_vector3		co;
	t_pair_double	values;
	
	radius = sphere->diameter / 2;
	co = diffvec3(p0, &sphere->center);
	values = calc_quad_equation(
			dot3(dirvec, dirvec),
			2 * dot3(dirvec, &co),
			dot3(&co, &co) - pow(radius, 2));
	return (calc_min_t(values));
}

double  intersect_cylinder(t_vector3 *p0, t_vector3 *dirvec, t_cylinder *cylinder)
{
	double          radius;
	t_vector3       co;
	t_pair_double   values_t;

	radius = cylinder->diameter / 2;
	co = diffvec3(p0, &cylinder->center);
	values_t = calc_quad_equation(
	dot3(dirvec, dirvec) - pow(dot3(&cylinder->orient, dirvec), 2.0),
	2 * (dot3(&co, dirvec) -
			dot3(dirvec, &cylinder->orient) * dot3(&co, &cylinder->orient)),
	dot3(&co, &co) - pow(dot3(&co, &cylinder->orient), 2.0) - pow(radius, 2.0));
	return (calc_cylinder_min_t(p0, &values_t, dirvec, cylinder));
}