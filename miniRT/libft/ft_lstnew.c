/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 00:06:35 by rmander           #+#    #+#             */
/*   Updated: 2020/11/17 00:08:16 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = NULL;
	if (!(node = malloc(sizeof(t_list))))
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
