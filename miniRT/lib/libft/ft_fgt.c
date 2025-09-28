/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fgt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 21:53:09 by rmander           #+#    #+#             */
/*   Updated: 2021/05/29 22:16:16 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

short	ft_fgt(double left, double right)
{
	if ((left > right) && !ft_fequal(left, right))
		return (TRUE);
	return (FALSE);
}