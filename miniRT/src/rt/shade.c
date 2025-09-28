/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 23:16:08 by rmander           #+#    #+#             */
/*   Updated: 2021/05/12 22:31:56 by rmander          ###   ########.fr       */
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


/* TODO put to utils */

/*
*
* 
* is_polygon_point - checks a ray point inside a polygon or not. N-polygon described by
* array of vertices size of N.
*
*/

#include "libft.h"
#include "linop.h"
#include <stddef.h>
#include <stdlib.h>

static t_vector3	*_is_polygon_point_cross_vecs(t_vector3 *p_vertex_vecs, size_t size)
{
	size_t		i;
	t_vector3	*vecs;

	vecs = malloc(sizeof(t_vector3) * size);
	if (!vecs)
		return (NULL);
	i = 0;
	while (i < size)
	{
		vecs[i] = cross3(&p_vertex_vecs[i], &p_vertex_vecs[(i + 1) % size]);
		++i;
	}
	return (vecs);

}

short int	_is_polygon_point(t_vector3 *cross_vecs, size_t size, t_vector3 *orient)
{
	double	check;
	size_t	i;
	
	i = 0;
	check = dot3(&cross_vecs[i++], orient);
	if (check > 0)
	{
		while (i < size)
			if (dot3(&cross_vecs[i++], orient) < 0)
				return (FALSE);
	}
	else if (check < 0)
	{
		while (i < size)
			if (dot3(&cross_vecs[i++], orient) > 0)
				return (FALSE);
	}
	return (TRUE);
}

short int	is_polygon_point(t_vector3 *p_hit,
				t_vector3 *vertices, t_vector3 *orient, size_t size)
{
	t_vector3	*p_vertex_vecs;
	t_vector3	*cross_vecs;
	size_t		i;
	short int	check;

	/* TODO check */

	check = FALSE;
	p_vertex_vecs = malloc(sizeof(t_vector3) * size);
	if (!p_vertex_vecs)
		return (FALSE);
	i = 0;
	while (i < size)
	{
		p_vertex_vecs[i] = diffvec3(&vertices[i], p_hit);
		++i;
	}
	cross_vecs = _is_polygon_point_cross_vecs(p_vertex_vecs, size);
	if (!cross_vecs)
	{
		free(p_vertex_vecs);
		return (FALSE);
	}
	check = _is_polygon_point(cross_vecs, size, orient);
	free(p_vertex_vecs);
	free(cross_vecs);
	return (check);
}
