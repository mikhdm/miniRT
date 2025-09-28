/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 00:55:06 by rmander           #+#    #+#             */
/*   Updated: 2020/11/07 17:25:37 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!n)
		return (0);
	while (--n)
	{
		if (*(unsigned char*)s1 != *(unsigned char*)s2)
			break ;
		++s1;
		++s2;
	}
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}
