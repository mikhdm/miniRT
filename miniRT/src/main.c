/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:37:11 by rmander           #+#    #+#             */
/*   Updated: 2021/04/14 00:12:59 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "mlx.h"
#include "event.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int main(void)
{
	t_meta	*meta;

	meta = malloc(sizeof(t_meta));
	if (!meta) {
		return (errno);
	}
	ft_defaults_meta(meta);

	meta->mlx = mlx_init();
	meta->window = mlx_new_window(meta->mlx, 800, 600, "Super Mega Ray Tracer Ever :)");
	mlx_hook(meta->window, X11_DESTROY_NOTIFY, MASK_NO_EVENT, ft_hook_close, meta);
	mlx_hook(meta->window, X11_KEY_PRESS, MASK_NO_EVENT, ft_hook_keypress, meta);
	mlx_loop(meta->window);
	return (0);
}
