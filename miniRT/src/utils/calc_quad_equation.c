/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_quad_equation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 01:11:03 by rmander           #+#    #+#             */
/*   Updated: 2021/04/21 03:38:34 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <float.h>
#include "utils.h"

t_pair_double	calc_quad_equation(double a, double b, double c)
{
	double			discriminant;
	t_pair_double	values;
	double			q;
	
	values = (t_pair_double) {.first = INFINITY, .second = INFINITY};
	discriminant = fma(b, b, -4 * a * c);
	if (discriminant < 0)
		return (values);
	else if (discriminant == 0)
	{
		values.first = -0.5 * b / a; 
		values.second = values.first;
	}
	else if (discriminant > 0)
	{
		if (b > 0)
			q = -0.5 * (b + sqrt(discriminant));
		else
			q = -0.5 * (b - sqrt(discriminant));
		values.first = q / a;
		values.second = c / q;
	}
	return (values);
}
