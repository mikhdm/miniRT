/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:39:21 by rmander           #+#    #+#             */
/*   Updated: 2021/05/29 17:45:23 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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
