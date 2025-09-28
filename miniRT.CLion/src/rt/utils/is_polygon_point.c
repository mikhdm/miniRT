/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_polygon_point.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 23:20:02 by rmander           #+#    #+#             */
/*   Updated: 2021/05/14 22:44:22 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linop.h"
#include "utils.h"
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <errno.h>

static t_vector3	*is_polygon_point_crosses(t_vector3 *p_vertex_vecs,
										   size_t size)
{
	size_t		i;
	t_vector3	*vecs;

	if (!alloca_to((void**)&vecs, sizeof(t_vector3) * size))
		return (NULL);
	i = 0;
	while (i < size)
	{
		vecs[i] = cross3(&p_vertex_vecs[i], &p_vertex_vecs[(i + 1) % size]);
		++i;
	}
	return (vecs);
}

static short int	is_polygon_point_check(t_vector3 *cross_vecs,
						size_t size, t_vector3 *orient)
{
	double	check;
	size_t	i;
	
	i = 0;
	check = dot3(&cross_vecs[i++], orient);
	if (check >= 0)
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

	check = FALSE;
	if (!alloca_to((void**)&p_vertex_vecs, sizeof(t_vector3) * size))
		exit(ENOMEM);
	i = 0;
	while (i < size)
	{
		p_vertex_vecs[i] = diffvec3(&vertices[i], p_hit);
		++i;
	}
	cross_vecs = is_polygon_point_crosses(p_vertex_vecs, size);
	if (!cross_vecs)
	{
		free(p_vertex_vecs);
		exit(ENOMEM);
	}
	check = is_polygon_point_check(cross_vecs, size, orient);
	free(p_vertex_vecs);
	free(cross_vecs);
	return (check);
}