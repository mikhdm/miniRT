/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 21:20:33 by rmander           #+#    #+#             */
/*   Updated: 2021/04/17 01:47:44 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "mlx.h"
#include "event.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_hook_close(int keycode, t_meta *meta)
{
	(void) keycode;
	(void) meta;
	// TODO check why mlx_destroy_window does segmentation fault
	exit(0);
}

int ft_hook_keypress(int keycode, t_meta *meta)
{
	if (keycode == KEY_ESC)
		if (meta->window)
		{
			mlx_destroy_window(meta->mlx, meta->window);
		}
	exit(0);
}
