/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linop.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:22:52 by rmander           #+#    #+#             */
/*   Updated: 2021/04/27 22:44:03 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINOP_H
# define LINOP_H

/*
*
* t_vector3 - structure to store 3D space vector
*
*/
typedef struct s_vector3
{
	double		x;
	double		y;
	double		z;
}	t_vector3;

double		dot3(t_vector3 *left, t_vector3 *right);
double		hypotvec3(t_vector3 *vec);
t_vector3	diffvec3(t_vector3 *left, t_vector3 *right);
t_vector3	sumvec3(t_vector3 *left, t_vector3 *right);
t_vector3	cmultvec3(double const value, t_vector3 *vector);
t_vector3	normvec3(t_vector3 *vec);

#endif 
