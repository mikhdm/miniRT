/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 21:20:33 by rmander           #+#    #+#             */
/*   Updated: 2021/04/26 23:22:56 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"
#include "canvas.h"
#include "mlx.h"
#include <stdlib.h>

int	ft_hook_close(int keycode, t_data *data)
{
	(void) keycode;
	(void) data;
	exit(0);
}

int ft_hook_keypress(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		if (data->window)
			mlx_destroy_window(data->mlx, data->window);
	exit(0);
}
