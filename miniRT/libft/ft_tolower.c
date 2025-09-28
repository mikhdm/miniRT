/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:07:42 by rmander           #+#    #+#             */
/*   Updated: 2020/11/20 00:12:40 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (TRUE);
	return (FALSE);
}

int			ft_tolower(int c)
{
	if (ft_isupper(c))
		c = c + 32;
	return (c);
}
