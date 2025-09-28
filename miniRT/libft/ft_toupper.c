/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:16:34 by rmander           #+#    #+#             */
/*   Updated: 2020/11/20 00:10:13 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (TRUE);
	return (FALSE);
}

int			ft_toupper(int c)
{
	if (ft_islower(c))
		c = c - 32;
	return (c);
}
