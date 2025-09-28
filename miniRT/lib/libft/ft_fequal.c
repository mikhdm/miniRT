/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fequal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 21:48:21 by rmander           #+#    #+#             */
/*   Updated: 2021/05/29 21:49:12 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <float.h>
#include <math.h>

short	ft_fequal(double left, double right)
{
	if (fabs(left - right) < DBL_EPSILON)
		return (TRUE);
	return (FALSE);
}