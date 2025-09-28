/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_min_t.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:18:48 by rmander           #+#    #+#             */
/*   Updated: 2021/06/07 04:29:46 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <math.h>

double	calc_min_t(t_pair_double values)
{
	if (values.first > values.second)
		swap_double(&values.first, &values.second);
	if (values.first < 0)
	{
		values.first = values.second;
		if (values.first < 0)
			return (INFINITY);
	}
	return (values.first);
}
