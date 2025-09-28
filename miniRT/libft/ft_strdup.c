/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 22:26:32 by rmander           #+#    #+#             */
/*   Updated: 2020/11/15 18:00:59 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	char	*d;

	dup = NULL;
	if (!(dup = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	d = dup;
	while ((*dup++ = *s1++))
		;
	return (d);
}
