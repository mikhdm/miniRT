/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:46:20 by rmander           #+#    #+#             */
/*   Updated: 2020/11/21 02:51:57 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_split_strslen(char const *str, char c)
{
	size_t	cnt;
	int		flag;

	cnt = 0;
	flag = OUT;
	while (*str)
	{
		if (*str != c)
		{
			if (flag == OUT)
				++cnt;
			flag = IN;
		}
		else
			flag = OUT;
		++str;
	}
	return (cnt);
}

static size_t	ft_split_strlen(char const *str, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*str && (*str != c))
	{
		++str;
		++cnt;
	}
	return (cnt);
}

static char		*ft_split_strdup(char const *str, char c)
{
	char	*s;
	char	*start;

	if (!(s = malloc(sizeof(char) * (ft_split_strlen(str, c) + 1))))
		return (NULL);
	start = s;
	while (*str && (*str != c))
		*s++ = *str++;
	*s = '\0';
	return (start);
}

static void		ft_split_free(char **strs, size_t cnt)
{
	while (cnt--)
		free(strs[cnt]);
	free(strs);
}

char			**ft_split(char const *s, char c)
{
	size_t	i;
	char	**strs;

	i = 0;
	strs = NULL;
	if (!(strs = malloc(sizeof(char*) * (ft_split_strslen(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			if (!(strs[i++] = ft_split_strdup(s, c)))
			{
				ft_split_free(strs, i);
				return (NULL);
			}
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	strs[i] = NULL;
	return (strs);
}
