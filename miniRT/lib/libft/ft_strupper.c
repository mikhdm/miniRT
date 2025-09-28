/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 00:30:23 by rmander           #+#    #+#             */
/*   Updated: 2021/05/27 08:03:46 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupper(char **str)
{
	char	*strp;

	strp = *str;
	while (*strp)
	{
		*strp = (char)ft_toupper(*strp);
		++strp;
	}
	return (*str);
}
