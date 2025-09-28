/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 00:54:40 by rmander           #+#    #+#             */
/*   Updated: 2020/11/14 21:37:52 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	dstsizeinit;

	srcsize = ft_strlen(src);
	dstsizeinit = ft_strlen(dst);
	if (dstsizeinit >= dstsize)
		return (dstsize + srcsize);
	dst += dstsizeinit;
	dstsize -= dstsizeinit;
	while (--dstsize && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (dstsizeinit + srcsize);
}
