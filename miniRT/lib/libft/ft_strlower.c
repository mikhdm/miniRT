/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 00:24:11 by rmander           #+#    #+#             */
/*   Updated: 2021/05/27 16:57:26 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlower(char **str)
{
	char	*strp;

	strp = *str;
	while (*strp)
	{
		*strp = (char)ft_tolower(*strp);
		++strp;
	}
	return (*str);
}
