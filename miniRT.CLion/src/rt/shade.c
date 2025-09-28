/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 23:16:08 by rmander           #+#    #+#             */
/*   Updated: 2021/05/13 23:48:49 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "linop.h"
#include "rayop.h"
#include "utils.h"
#include <stdlib.h>
#include <errno.h>

int	shade_sphere(t_data *data, t_vector3 *p0, t_vector3 *dirvec,
				 t_pair_figure_double *pair_figure_t)
{
	int         color;
	t_vector3	p_hit;
	t_vector3	orient;
	t_sphere    *sphere;
	
	sphere = (t_sphere *)pair_figure_t->figure->content;
	color = sphere->color;
	p_hit = calc_ray_point(p0, dirvec, pair_figure_t->t);
	orient = calc_sphere_orient(&p_hit, sphere);
	return (light(data, &p_hit, &orient, color));
}

int shade_plane(t_data *data, t_vector3 *p0, t_vector3 *dirvec,
				t_pair_figure_double *pair_figure_t)
{
	int			color;
	t_vector3	p_hit;
	t_plane     *plane;

	plane = (t_plane *)pair_figure_t->figure->content;
	color = plane->color;
	p_hit = calc_ray_point(p0, dirvec, pair_figure_t->t);
	return (light(data, &p_hit, &plane->orient, color));
}

int	shade_square(t_data *data, t_vector3 *p0, t_vector3 *dirvec,
				 t_pair_figure_double *pair_figure_t)
{
	int         color;
	t_vector3	p_hit;
	t_vector3	*vertices;
	t_square    *square;

	square = (t_square *)pair_figure_t->figure->content;
	color = square->color;
	p_hit = calc_ray_point(p0, dirvec, pair_figure_t->t);
	vertices = gen_square_vertices(square);
	if (!vertices)
		exit(ENOMEM);
	if (is_polygon_point(&p_hit, vertices, &square->orient, 4))
		return (light(data, &p_hit, &square->orient, color));
	return (COLOR_BACKGROUND);
}

int	shade_triangle(t_data *data, t_vector3 *p0, t_vector3 *dirvec,
				   t_pair_figure_double *pair_figure_t)
{
	int         color;
	t_vector3   vertices[3];
	t_vector3   p_hit;
	t_vector3   orient;
	t_triangle  *triangle;

	triangle = (t_triangle *)pair_figure_t->figure->content;
	color = triangle->color;
	p_hit = calc_ray_point(p0, dirvec, pair_figure_t->t);
	orient = calc_triangle_orient(triangle);
	vertices[0] = triangle->x;
	vertices[1] = triangle->y;
	vertices[2] = triangle->z;
	if (is_polygon_point(&p_hit, vertices, &orient, 3))
		return (light(data, &p_hit, &orient, color));
	return (COLOR_BACKGROUND);
}

int shade_cylinder(t_data *data, t_vector3 *p0, t_vector3 *dirvec,
				   t_pair_figure_double *pair_figure_t)
{
	t_cylinder *cylinder;

	cylinder = (t_cylinder *)pair_figure_t->figure->content;
	return (cylinder->color);
}
