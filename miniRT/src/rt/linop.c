/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linop.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:31:14 by rmander           #+#    #+#             */
/*   Updated: 2021/04/23 17:02:58 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"
#include "linop.h"

double	dot3(t_vector3 *left, t_vector3 *right)
{
	double product;

	product = (left->x*right->x
				+ left->y*right->y
				+ left->z*right->z);
	return (product);
}

t_vector3	diffvec3(t_vector3 *left, t_vector3 *right)
{
	t_vector3	diffvec;

	diffvec = (t_vector3) {.x = .0, .y = .0, .z = .0};
	diffvec.x = left->x - right->x;
	diffvec.y = left->y - right->y;
	diffvec.z = left->z - right->z;
	return (diffvec);
}

t_vector3	sumvec3(t_vector3 *left, t_vector3 *right)
{
	t_vector3	sumvec;

	sumvec = (t_vector3) {.x = .0, .y = .0, .z = .0};
	sumvec.x = left->x + right->x;
	sumvec.y = left->y + right->y;
	sumvec.z = left->z + right->z;
	return (sumvec);
}

t_vector3	cmultvec3(double const value, t_vector3 *vector)
{
	t_vector3 cmultvec;

	cmultvec = (t_vector3) {.x = .0, .y = .0, .z = .0};
	cmultvec.x = value * vector->x;
	cmultvec.y = value * vector->y;
	cmultvec.z = value * vector->z;
	return (cmultvec);
}

double		hypot3(double x, double y, double z)
{
	return (sqrt(x*x + y*y + z*z));
}
