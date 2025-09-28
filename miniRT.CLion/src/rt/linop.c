/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linop.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:31:14 by rmander           #+#    #+#             */
/*   Updated: 2021/05/04 22:36:01 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linop.h"
#include "libft.h"
#include <math.h>

double	dot3(t_vector3 *left, t_vector3 *right)
{
	double product;

	product = (left->x*right->x
				+ left->y*right->y
				+ left->z*right->z);
	return (product);
}

t_vector3	cross3(t_vector3 *left, t_vector3 *right)
{
	t_vector3	crossvec;

	crossvec = (t_vector3) {.x = .0, .y = .0, .z = .0};
	crossvec.x = fma(left->y, right->z, -left->z * right->y);
	crossvec.y = fma(right->x, left->z, -left->x * right->z);
	crossvec.z = fma(left->x, right->y, -right->x * left->y);
	return (crossvec);
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

double		hypotvec3(t_vector3 *vec)
{
	return (sqrt(dot3(vec, vec)));
}

t_vector3	normvec3(t_vector3 *vec)
{
	double	length;

	length = hypotvec3(vec);
	return (cmultvec3(pow(length, -1), vec));
}

short int	iscollinvec3(t_vector3 *left, t_vector3 *right)
{
	short int	collinear;
	t_vector3	crossvec;

	collinear = FALSE;
	crossvec = cross3(left, right);
	if (fabs(crossvec.x - 0.0) < 1e-14 &&
		fabs(crossvec.y - 0.0) < 1e-14 &&
		fabs(crossvec.z - 0.0) < 1e-14)
		collinear = TRUE;
	return (collinear);
}
