/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 22:16:24 by rmander           #+#    #+#             */
/*   Updated: 2021/05/29 22:27:41 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

short	ft_flt(double left, double right)
{
	if ((left < right) && !ft_fequal(left, right))
		return (TRUE);
	return (FALSE);
}
