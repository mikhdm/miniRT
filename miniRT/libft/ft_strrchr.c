/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 00:54:03 by rmander           #+#    #+#             */
/*   Updated: 2020/11/13 20:51:26 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*sp;

	sp = (char*)s;
	sp = sp + ft_strlen(s);
	while (sp != s)
	{
		if (*sp == (char)c)
			return (sp);
		--sp;
	}
	if (*sp == (char)c)
		return (sp);
	return (NULL);
}
