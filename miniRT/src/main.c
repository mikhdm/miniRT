/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:37:11 by rmander           #+#    #+#             */
/*   Updated: 2021/04/17 03:58:16 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "mlx.h"
#include "event.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static void	ft_init(t_meta *meta, t_screen *screen)
{
	meta->mlx = mlx_init();
	meta->window = mlx_new_window(meta->mlx,
					screen->width, screen->height, screen->title);
	meta->img = mlx_new_image(meta->mlx, screen->width, screen->height); 
	meta->addr = mlx_get_data_addr(meta->img, &meta->bpp, &meta->length,
					&meta->endian);
}

int main(void)
{
	t_meta		meta;
	t_screen 	screen; 

	meta = (t_meta) {.mlx = NULL, .window = NULL, .img = NULL,
					.addr = NULL, .bpp = 0, .length = 0, .endian = 0};
	screen = (t_screen) {.width = 800, .height = 600,
						.title = "Super Mega Ray Tracer Ever :)"};
	
	ft_init(&meta, &screen);
	
	/* LOG */
	printf("bpp: %d;\nline length: %d;\nendian: %d;\n",
		meta.bpp, meta.length, meta.endian); 
	/* END LOG */

	ft_putpixel(&meta, 400, 300, 0x00ffffff);
	
	mlx_hook(meta.window,
		X11_DESTROY_NOTIFY, MASK_NO_EVENT, ft_hook_close, &meta);
	mlx_hook(meta.window,
		X11_KEY_PRESS, MASK_NO_EVENT, ft_hook_keypress, &meta);

	mlx_put_image_to_window(meta.mlx, meta.window, meta.img, 0, 0);
	mlx_loop(meta.mlx);
	return (0);
}
