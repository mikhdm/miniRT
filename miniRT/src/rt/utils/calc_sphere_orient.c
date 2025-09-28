/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_sphere_orient.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:59:23 by rmander           #+#    #+#             */
/*   Updated: 2021/04/26 23:22:58 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rayop.h"
#include "linop.h"

t_vector3	calc_sphere_orient(t_vector3 *point, t_sphere *sphere)
{
	t_vector3	orient;
	double		length;

	orient = diffvec3(point, &sphere->center);
	length = hypotvec3(&orient); 
	return (cmultvec3((double const) pow(length, -1), &orient)); 
}

