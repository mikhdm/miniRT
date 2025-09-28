/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_of.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 05:12:05 by rmander           #+#    #+#             */
/*   Updated: 2021/06/07 05:12:05 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

short	one_of(char *value, char const **strs)
{
	while (*strs)
	{
		if (ft_strcmp(value, *strs++) == 0)
			return (TRUE);
	}
	return (FALSE);
}
