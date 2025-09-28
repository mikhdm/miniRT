/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_sphere_orient.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:59:23 by rmander           #+#    #+#             */
/*   Updated: 2021/04/25 20:01:54 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "linop.h"
#include "figure.h"

t_vector3	calc_sphere_orient(t_vector3 *point, t_sphere *sphere)
{
	t_vector3	orient;
	t_vector3	length;

	orient = diffvec3(&point, &sphere->center);
	length = hypotvec3(&orient); 
	return (cmultvec3((double const) pow(length, -1), &orient)); 
}

