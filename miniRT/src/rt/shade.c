/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 23:16:08 by rmander           #+#    #+#             */
/*   Updated: 2021/05/12 23:27:13 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "linop.h"
#include "light.h"
#include "utils.h"

int	shade_sphere(t_data *data,
		t_sphere *sphere, t_vector3 *dirvec, double t)
{
	int	color;
	t_vector3	p_hit;

	p_hit = calc_ray_point(data, dirvec, t);
	orient = calc_sphere_orient(&p_hit, sphere);
	color = light(data, &p_hit, &orient, sphere->color);
	return (color);
}

int shade_plane(t_data *data,
		t_plane *plane, t_vector3 *dirvec, double t)
{
	int			color;
	t_vector3	p_hit;

	p_hit = calc_ray_point(data, dirvec, t);
	color = light(data, &p_hit, &plane->orient, color);
	return (color);
}

int	shade_square(t_data *data,
		t_square *square, t_vector3 *dirvec, double t)
{
	int	color;
	t_vector3	p_hit;
	t_vector3	vertices[4];

	color = square->color; 
	p_hit = calc_ray_point(data, dirvec, t);
	vertices = gen_square_vertices(square);  
	if (is_polygon_point(&p_hit, vertices, &square->orient, 4))
		color = light(data, &p_hit, &square->orient, color);
	return (color);

}

int	shade_triangle(t_data *data,
		t_triangle *triangle, t_vector3 *dirvec, double t)
{
	/* TODO */
	(void)data;
	(void)triangle;
	(void)dirvec;
	(void)t;
	return (COLOR_BACKGROUND);
}


int shade_cylinder(t_data *data,
		t_cylinder *cylinder, t_vector3 *dirvec, double t)
{
	/* TODO */
	(void)data;
	(void)cylinder;
	(void)dirvec;
	(void)t;
	return (0x0);
}
