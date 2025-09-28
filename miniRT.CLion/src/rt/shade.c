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
	t_square    *square;

	square = (t_square *)pair_figure_t->figure->content;
	color = square->color;
	p_hit = calc_ray_point(p0, dirvec, pair_figure_t->t);
	return (light(data, &p_hit, &square->orient, color));
}

int	shade_triangle(t_data *data, t_vector3 *p0, t_vector3 *dirvec,
				   t_pair_figure_double *pair_figure_t)
{
	int         color;
	t_vector3   p_hit;
	t_vector3   orient;
	t_triangle  *triangle;

	triangle = (t_triangle *)pair_figure_t->figure->content;
	color = triangle->color;
	p_hit = calc_ray_point(p0, dirvec, pair_figure_t->t);
	orient = calc_triangle_orient(triangle);
	return (light(data, &p_hit, &orient, color));
}

int shade_cylinder(t_data *data, t_vector3 *p0, t_vector3 *dirvec,
				   t_pair_figure_double *pair_figure_t)
{
	t_cylinder *cylinder;

	cylinder = (t_cylinder *)pair_figure_t->figure->content;
	return (cylinder->color);
}
