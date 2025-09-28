/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:37:11 by rmander           #+#    #+#             */
/*   Updated: 2021/04/17 22:05:52 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "mlx.h"
#include "event.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static void	ft_init(t_meta *meta)
{
	meta->mlx = mlx_init();
	meta->window = mlx_new_window(meta->mlx,
					meta->screen->width, meta->screen->height, meta->screen->title);
	meta->img = mlx_new_image(meta->mlx, meta->screen->width, meta->screen->height); 
	meta->addr = mlx_get_data_addr(meta->img, &meta->bpp, &meta->length,
					&meta->endian);
}

int main(void)
{
	t_meta		meta;
	t_screen 	screen; 
	t_camera	cam;
	t_vector3	*plane;

	plane = NULL;
	screen = (t_screen) {.width = 800, .height = 600,
						.title = "Super Mega Ray Tracer Ever :)"};

	/* camera position */
	cam = (t_camera) {.x = .0, .y = .0, .z = .0,
					.orient = (t_vector3d) {.x = 0, .y = 0, .z = 1}};
	meta = (t_meta) {.mlx = NULL, .window = NULL, .img = NULL,
					.addr = NULL, .bpp = 0, .length = 0, .endian = 0,
					.screen = &screen, .cam = &cam};
	ft_init(&meta);
	
	/* LOG */
	printf("bpp: %d;\nline length: %d;\nendian: %d;\n",
		meta.bpp, meta.length, meta.endian); 
	/* END LOG */
	
	mlx_hook(meta.window,
		X11_DESTROY_NOTIFY, MASK_NO_EVENT, ft_hook_close, &meta);
	mlx_hook(meta.window,
		X11_KEY_PRESS, MASK_NO_EVENT, ft_hook_keypress, &meta);
	mlx_put_image_to_window(meta.mlx, meta.window, meta.img, 0, 0);
	mlx_loop(meta.mlx);
	return (0);
}
