/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 21:20:33 by rmander           #+#    #+#             */
/*   Updated: 2021/05/09 19:11:24 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"
#include "canvas.h"
#include "mlx.h"
#include <stdlib.h>

static int	hook_close(int keycode, t_data *data)
{
	(void) keycode;
	(void) data;
	exit(0);
}

static int	hook_keypress(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		(void) data;
		/* if (data->window) */
		/* 	mlx_destroy_window(data->mlx, data->window); */
		exit(0);
	}
	return (keycode);
}

void	bind_hooks(t_data *data)
{
	mlx_hook(data->window,
		X11_DESTROY_NOTIFY, MASK_NO_EVENT, &hook_close, &data);
	mlx_hook(data->window,
		X11_KEY_PRESS, MASK_NO_EVENT, &hook_keypress, &data);
}
