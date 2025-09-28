/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 06:36:02 by rmander           #+#    #+#             */
/*   Updated: 2021/06/01 06:37:54 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linop.h"
#include "libft.h"
#include "parsing/validate.h"
#include <stddef.h>

t_vector3	*serialize_point(char **strs_point, t_vector3 *point)
{
	size_t strslen;

	strslen = ft_strslen(strs_point);
	if (strslen != 3)
		return (NULL);
	if (!valid_point3((const char **)strs_point, strslen, point))
		return (NULL);
	return (point);
}
