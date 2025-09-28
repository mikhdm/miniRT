/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:42:14 by rmander           #+#    #+#             */
/*   Updated: 2021/04/19 01:09:53 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct t_pair_double
{
	double first;
	double second;
}	t_pair_double;

t_pair_double	calc_quad_equation(double a, double b, double c);

#endif
