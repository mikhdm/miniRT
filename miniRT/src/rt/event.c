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

static void	hook_close(void *param)
{
    t_data *data = (t_data *)param;
    mlx_close_window(data->mlx);
    mlx_terminate(data->mlx);
    exit(0);
}

static void	hook_keypress(mlx_key_data_t keydata, void *param)
{
    t_data *data = (t_data *)param;

    const keys_t keycode = keydata.key;
    if (keycode == MLX_KEY_ESCAPE)
    {
        cleanup(data);
        exit(0);
    }
    else if (keycode == MLX_KEY_LEFT)
    {
        mlx_reset_image(data);
        render(data, get_cam(data, POS_CAM_PREV),
               &(t_pair_double){.first = 1.0, .second = INFINITY});
        mlx_image_to_window(data->mlx, data->img, 0, 0);
    }
    else if (keycode == MLX_KEY_RIGHT)
    {
        mlx_reset_image(data);
        render(data, get_cam(data, POS_CAM_NEXT),
            &(t_pair_double){.first = 1.0, .second = INFINITY});
        mlx_image_to_window(data->mlx, data->img, 0, 0);
    }
}

void	bind_hooks(t_data *data)
{
    mlx_close_hook(data->mlx, hook_close, data);
    mlx_key_hook(data->mlx, hook_keypress, data);
}