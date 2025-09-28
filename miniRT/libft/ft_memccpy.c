/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 00:58:10 by rmander           #+#    #+#             */
/*   Updated: 2020/11/13 20:50:21 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;

	d = dst;
	while (n--)
	{
		*d = *(unsigned char*)src;
		if (*d == (unsigned char)c)
			return (++d);
		++d;
		++src;
	}
	return (NULL);
}
