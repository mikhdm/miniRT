/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 06:37:05 by rmander           #+#    #+#             */
/*   Updated: 2021/06/01 06:37:42 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/validate.h"
#include "libft.h"
#include <stddef.h>

int	*serialize_rgb(char **strs_rgb, int *rgba)
{
	size_t	strslen;

	strslen = ft_strslen(strs_rgb);
	if (strslen != 3)
		return (NULL);
	if (!valid_rgb((const char **)strs_rgb, strslen, rgba))
		return (NULL);
	return (rgba);
}
