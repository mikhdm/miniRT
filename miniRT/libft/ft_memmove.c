/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 00:55:00 by rmander           #+#    #+#             */
/*   Updated: 2020/11/13 20:50:32 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void		*ft_memmove_backward(void *dst, const void *src, size_t len)
{
	unsigned char	*d;

	d = dst;
	while (len--)
		*(d + len) = *(unsigned char*)(src + len);
	return (dst);
}

static void		*ft_memmove_forward(void *dst, const void *src, size_t len)
{
	unsigned char	*d;

	d = dst;
	while (len--)
		*d++ = *(unsigned char*)src++;
	return (dst);
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src < dst)
		return (ft_memmove_backward(dst, src, len));
	else if (src > dst)
		return (ft_memmove_forward(dst, src, len));
	else
		return (dst);
}
