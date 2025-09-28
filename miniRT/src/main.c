/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:37:11 by rmander           #+#    #+#             */
/*   Updated: 2021/05/09 19:11:35 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "light.h"
#include "event.h"
#include "render.h"
#include "mlx.h"
#include <math.h>
#include <stddef.h>
#include <stdio.h>

static void	init(t_data *data)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(
							data->mlx,
							data->screen->width,
							data->screen->height,
							data->screen->title);
	data->img = mlx_new_image(
							data->mlx,
							data->screen->width,
							data->screen->height); 
	data->addr = mlx_get_data_addr(
							data->img,
							&data->bpp,
							&data->length,
							&data->endian);
}

void test(t_data *data);

int main(void)
{
	t_data			data;
	t_screen		screen;
	t_camera		cam;
	t_sphere		sphere;
	t_sphere		sphere2;
	t_plane			plane;
	t_square		square;
	t_figure		figure1;
	t_figure		figure2;
	t_figure		figure3;
	t_viewport		viewport;
	t_pair_double	stepsrange;
	t_light			lights;
	t_light			light2;
	t_ambience		ambience;
	
	screen = (t_screen) {.width = 800, .height = 600, .title = "miniRT"};

	cam = (t_camera) {.center = (t_vector3) {.x = .0, .y = .0, .z = 0.0},
					.orient = (t_vector3) {.x = 0, .y = 0, .z = 1},
					.fov = 60};

	data = (t_data) {.mlx = NULL, .window = NULL, .img = NULL,
					.addr = NULL, .bpp = 0, .length = 0, .endian = 0,
					.screen = &screen, .cam = &cam, .viewport = NULL};
	
	ambience = (t_ambience) {.intensity = 0.5, .color = 0xffff00};
	
	light2 = (t_light) {.brightness = 1.0, .color = 0xffff00,
					.center = (t_vector3) {.x = -2, .y = 2, .z = 10},
					.next = NULL};

	lights = (t_light) {.brightness = 1.0, .color = 0x00ff00,
		.center = (t_vector3) {.x = 0, .y = 0, .z = 2},
		.next = NULL};

	(void) light2;

	data.light = &lights;
	data.ambience = &ambience;

	viewport = calc_viewport(&data);

	data.viewport = &viewport;

	sphere2 = (t_sphere) {
						.label = LABEL_SPHERE,
						.color = 0x00ff00,
						.diameter = 2,
						.center = (t_vector3) {.x = 0, .y = 0.5, .z = 10}};

	sphere = (t_sphere) {
						.label = LABEL_SPHERE,
						.color = 0xffffff,
						.diameter = 5,
						.center = (t_vector3) {.x = 0, .y = 0, .z = 15}};

	plane = (t_plane) {
						.label = LABEL_PLANE,
						.color = 0xff00ff,
						.center = (t_vector3) {.x = 0, .y = 0, .z = 6},
						.orient = (t_vector3) {.x = 0,
												.y = 5/sqrt(50),
												.z = 5/sqrt(50)}};

	square = (t_square) {
						.label = LABEL_SQUARE,
						.color = 0xff0000,
						.center = (t_vector3) {.x = 0, .y = 2, .z = 20},
						.orient = (t_vector3) {.x = 0, .y = .0, .z = 1},
						.size = 8.0};
	
	figure3 = (t_figure) {.content = &sphere2, .next = NULL};
	figure2 = (t_figure) {.content = &plane, .next = &figure3};
	figure1 = (t_figure) {.content = &sphere, .next = &figure2};

	data.figures = &figures;

	init(&data);
	
	/* LOG */
	printf("bpp: %d;\nline length: %d;\nendian: %d;\n",
		data.bpp, data.length, data.endian); 
	/* END LOG */
	test(&data);

	range = (t_pair_double) {.first = 1.0, .second = INFINITY};
	render(&data, &range);
	mlx_put_image_to_window(data.mlx, data.window, data.img, 0, 0);
	bind_hooks(&data);
	mlx_loop(data.mlx);
	return (0);
}
