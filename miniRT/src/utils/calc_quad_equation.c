/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_quad_equation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 01:11:03 by rmander           #+#    #+#             */
/*   Updated: 2021/04/19 02:02:50 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "utils.h"

t_pair_double	calc_quad_equation(double a, double b, double c)
{
	double			discriminant;
	t_pair_double	values;
	
	values = (t_pair_double) {.first = INFINITY, .second = INFINITY};
	discriminant = fma(b, b, -4 * a * c);
	if (discriminant < 0)
		return (values);
	values.first = (-b + sqrt(discriminant)) / (2 * a);
	values.second = (-b - sqrt(discriminant)) / (2 * a);
	return (values);
}
