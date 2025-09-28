/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 21:20:33 by rmander           #+#    #+#             */
/*   Updated: 2021/06/07 16:04:03 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"
#include "canvas.h"
#include "render.h"
#include "utils.h"
#include "parsing/cleanup.h"
#include "MLX42/MLX42.h"
#include <math.h>
#include <stdlib.h>

static int	hook_close(void *param)
{
	exit(0);
}

static int	hook_keypress(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		cleanup(data);
		exit(0);
	}
	else if (keycode == KEY_LEFT)
	{
		mlx_reset_image(data);
		render(data, get_cam(data, POS_CAM_PREV),
			   &(t_pair_double){.first = 1.0, .second = INFINITY});
		mlx_image_to_window(data->mlx, data->img, 0, 0);
	}
	else if (keycode == KEY_RIGHT)
	{
		mlx_reset_image(data);
		render(data, get_cam(data, POS_CAM_NEXT),
			&(t_pair_double){.first = 1.0, .second = INFINITY});
		mlx_image_to_window(data->mlx, data->img, 0, 0);
	}
	return (keycode);
}

void	bind_hooks(t_data *data)
{
	mlx_close_hook(data->mlx, &hook_close, data);
	mlx_key_hook(data->mlx,
		X11_KEY_PRESS, MASK_NO_EVENT, &hook_keypress, data);
}
