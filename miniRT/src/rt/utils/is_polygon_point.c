/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_polygon_point.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 23:20:02 by rmander           #+#    #+#             */
/*   Updated: 2021/05/12 23:22:44 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "canvas.h"
#include "linop.h"
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static t_vector3	*_is_polygon_point_cross_vecs(
						t_vector3 *p_vertex_vecs, size_t size)
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

static short int	_is_polygon_point(t_vector3 *cross_vecs,
						size_t size, t_vector3 *orient)
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
