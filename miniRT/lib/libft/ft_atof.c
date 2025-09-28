/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 05:18:54 by rmander           #+#    #+#             */
/*   Updated: 2021/05/24 23:55:45 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

double  ft_atof(const char *str)
{
	long double value;

	short	neg;

	neg = FALSE;
	value = 0.0;
	while (ft_isspace(*str))
		++str;
	if (*str == '-')
		neg = TRUE;



	return ((double)value);
}