/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 18:11:13 by rmander           #+#    #+#             */
/*   Updated: 2021/06/02 18:11:50 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include <unistd.h>
#include <stdlib.h>

void cleanup(t_data *data)
{
	if (!data)
		return ;
	if (data->screen)
		free(data->screen);

	/* TODO */

	if (data->fildes != -1)
		close(data->fildes);
	free(data);
}
