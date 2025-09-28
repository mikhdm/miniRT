/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_faceted_orient.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:18:26 by rmander           #+#    #+#             */
/*   Updated: 2021/06/06 18:08:20 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linop.h"
#include "libft.h"

t_vector3	calc_faceted_orient(t_vector3 *dirvec, t_vector3 *orient)
{
	t_vector3	vec;
	t_vector3	facing_ratio;

	vec = *orient;
	facing_ratio = cmultvec3(-1, dirvec);
	facing_ratio = normvec3(&facing_ratio);
	if (ft_flt(dot3(&facing_ratio, orient), 0))
		vec = cmultvec3(-1, orient);
	return (vec);
}
