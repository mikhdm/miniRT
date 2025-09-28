/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:06:49 by rmander           #+#    #+#             */
/*   Updated: 2020/11/13 20:49:20 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	void	*s;

	s = b;
	while (len--)
		*(unsigned char*)b++ = (unsigned char)c;
	return (s);
}
