/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 03:02:29 by rmander           #+#    #+#             */
/*   Updated: 2021/05/30 16:13:23 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_strsfree(char **strs)
{
	char	**s;

	s = strs;
	while (*s)
		free(*s++);
	free(strs);
	strs = NULL;
}
