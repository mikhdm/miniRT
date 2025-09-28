/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:09:56 by rmander           #+#    #+#             */
/*   Updated: 2020/11/20 00:18:01 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (TRUE);
	return (FALSE);
}

static int	ft_islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (TRUE);
	return (FALSE);
}

int			ft_isalpha(int c)
{
	return (ft_islower(c) || ft_isupper(c));
}
