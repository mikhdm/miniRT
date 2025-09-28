/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:49:03 by rmander           #+#    #+#             */
/*   Updated: 2020/11/15 17:59:38 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*data;
	unsigned int	size;
	unsigned int	i;

	if (!f)
		return (NULL);
	size = ft_strlen(s);
	data = NULL;
	if (!(data = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		data[i] = f(i, s[i]);
		++i;
	}
	data[i] = '\0';
	return (data);
}
