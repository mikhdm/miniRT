/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:42:14 by rmander           #+#    #+#             */
/*   Updated: 2021/04/26 21:14:57 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "canvas.h"
#include "linop.h"

typedef struct	t_pair_double
{
	double		first;
	double		second;
}				t_pair_double;

t_pair_double	calc_quad_equation(double a, double b, double c);
t_vector3		calc_sphere_orient(t_vector3 *point, t_sphere *sphere);
double			deg_to_rad(double deg);

// TODO check for nessecity
double			rad_to_deg(double rad);
void			ft_swap_double(double *left, double *right);

#endif
