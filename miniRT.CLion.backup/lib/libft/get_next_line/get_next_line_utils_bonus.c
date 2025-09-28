/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 04:03:34 by rmander           #+#    #+#             */
/*   Updated: 2021/04/11 19:07:50 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line_bonus.h"

size_t	ft_strlen_until(const char *s, const char sym)
{
	size_t	i;

	i = 0;
	while (*s && (*s != sym))
	{
		++i;
		++s;
	}
	return (i);
}

char	*ft_strdup_until(const char *s1, const char sym)
{
	char	*dup;
	char	*d;

	dup = malloc((ft_strlen_until(s1, sym) + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	d = dup;
	while (*s1 && *s1 != sym)
		*dup++ = *s1++;
	*dup = '\0';
	return (d);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buf;
	size_t	s1_size;
	size_t	s2_size;
	size_t	n;

	n = 0;
	s1_size = ft_strlen_until(s1, '\0');
	s2_size = ft_strlen_until(s2, '\0');
	buf = malloc((s1_size + s2_size + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	n = s1_size;
	while (n--)
		*buf++ = *s1++;
	n = s2_size;
	while (n--)
		*buf++ = *s2++;
	*buf = '\0';
	buf -= s1_size + s2_size;
	return (buf);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		++s;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;

	srcsize = ft_strlen_until(src, '\0');
	if (!dst || !dstsize)
		return (srcsize);
	while (--dstsize && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (srcsize);
}
