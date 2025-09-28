/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 02:20:50 by rmander           #+#    #+#             */
/*   Updated: 2020/11/20 02:17:13 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buf;
	size_t	s1size;
	size_t	s2size;

	buf = NULL;
	s1size = ft_strlen(s1);
	s2size = ft_strlen(s2);
	if (!(buf = malloc(sizeof(char) * (s1size + s2size + 1))))
		return (NULL);
	buf = ft_memcpy(buf, s1, s1size);
	buf += s1size;
	buf = ft_memcpy(buf, s2, s2size);
	buf += s2size;
	*buf = '\0';
	buf -= s1size + s2size;
	return (buf);
}
