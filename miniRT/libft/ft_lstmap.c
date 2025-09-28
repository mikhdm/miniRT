/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:53:27 by rmander           #+#    #+#             */
/*   Updated: 2020/11/22 15:28:56 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*curr;

	head = NULL;
	curr = NULL;
	if (!(head = ft_lstnew(f(lst->content))))
		return (NULL);
	curr = head;
	lst = lst->next;
	while (lst)
	{
		if (!(curr->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		curr = curr->next;
		lst = lst->next;
	}
	return (head);
}
