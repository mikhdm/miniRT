/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_orient.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 21:51:44 by rmander           #+#    #+#             */
/*   Updated: 2021/05/31 05:14:40 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "linop.h"
#include <stddef.h>

short valid_orient(const char **strs_orient, size_t strslen, t_vector3 *orient)
{
	const char *str;
	size_t 		i;

	i = 0;
	str = NULL;
	while (i < strslen)
	{
		str = strs_orient[i++];
		if (!str || !*str)
			return (FALSE);
		if (!ft_isfloatable(str))
			return (FALSE);
	}
	orient->x = ft_atof(strs_orient[0]);
	orient->y = ft_atof(strs_orient[1]);
	orient->z = ft_atof(strs_orient[2]);
	if (!ft_fequal(hypotvec3(orient), 1))
		return (FALSE);
	return (TRUE);
}