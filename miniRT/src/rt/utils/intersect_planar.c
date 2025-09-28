/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_planar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:45:02 by rmander           #+#    #+#             */
/*   Updated: 2021/06/04 21:41:52 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "linop.h"
#include "libft.h"
#include <math.h>

double	intersected_planar(t_vector3 *p0, t_vector3 *dirvec, t_vector3 *center,
			t_vector3 *orient)
{
	double		t;
	t_vector3	co;
	double		denom;

	t = INFINITY;
	co = diffvec3(center, p0);
	denom = dot3(dirvec, orient);
	if (ft_fgt(fabs(denom), 0))
	{
		t = dot3(&co, orient) / denom;
		if (ft_fgt(t, 0) || ft_fequal(t, 0))
			return (t);
	}
	return (INFINITY);
}
