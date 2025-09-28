/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:45:48 by rmander           #+#    #+#             */
/*   Updated: 2020/11/12 21:45:51 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while (--n && *s1 && *s2)
	{
		if (*s1 != *s2)
			break ;
		++s1;
		++s2;
	}
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}
