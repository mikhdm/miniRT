/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_figure_append.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 07:09:04 by rmander           #+#    #+#             */
/*   Updated: 2021/06/01 07:09:04 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

void	lst_figure_append(t_figure **head, t_figure *new)
{
	t_figure	**curr;

	curr = head;
	if (!*curr)
		*curr = new;
	else
	{
		while ((*curr)->next)
			curr = &((*curr)->next);
		(*curr)->next = new;
	}
}
