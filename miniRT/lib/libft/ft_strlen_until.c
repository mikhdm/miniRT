/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:40:20 by rmander           #+#    #+#             */
/*   Updated: 2021/05/29 17:45:27 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

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
