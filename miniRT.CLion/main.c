/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:37:11 by rmander           #+#    #+#             */
/*   Updated: 2021/05/14 22:05:52 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "event.h"
#include "render.h"
#include "mlx.h"
#include <math.h>
#include <stddef.h>

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

t_data *parse()
{
	t_data  data;
}

int main(void)
{
	t_data			data;
	t_screen		screen;
	t_camera		cam;
	t_sphere		sphere;
	t_sphere		sphere2;
	t_plane			plane;
	t_square		square;
	t_triangle      triangle;
	t_cylinder      cylinder;
	t_cylinder      cylinder2;
	t_figure		figure1;
	t_figure		figure2;
	t_figure		figure3;
	t_figure		figure4;
	t_figure		figure5;
	t_figure        figure6;
	t_pair_double	range;
	t_light			lights;
	t_light			light2;
	t_light         light3;
	t_ambience		ambience;
	t_viewport      viewport;

	screen = (t_screen) {.width = 800, .height = 600, .title = "miniRT"};

	cam = (t_camera) {.center = (t_vector3) {.x = 5, .y = 10, .z = 20},
					.orient = (t_vector3) {.x = -1/sqrt(6), .y = -1/sqrt(6), .z = -2/sqrt(6)},
					.viewport = NULL,
					.fov = 90};

	data = (t_data) {.mlx = NULL, .window = NULL, .img = NULL,
					.addr = NULL, .bpp = 0, .length = 0, .endian = 0,
					.screen = &screen, .cam = &cam};
	
	ambience = (t_ambience) {.intensity = 0.2, .color = 0xffffff};
	light3 = (t_light) {.brightness = 1.0, .color = 0xffffff,
					    .center = (t_vector3) {.x = 0, .y = 1, .z = 0},
					    .next = NULL};
	light2 = (t_light) {.brightness = 1.0, .color = 0xffffff,
					.center = (t_vector3) {.x = -1.5, .y = 2, .z = 3},
					.next = &light3};
	lights = (t_light) {.brightness = 1.0, .color = 0xffffff,
		.center = (t_vector3) {.x = 0, .y = 10, .z = 5},
		.next = NULL};

	data.light = &lights;
	data.ambience = &ambience;
	viewport = calc_viewport(&data, data.cam);
	data.cam->viewport = &viewport;

	sphere2 = (t_sphere) {
						.color = 0xaa0000,
						.diameter = 2,
						.center = (t_vector3) {.x = -1, .y = -0.5, .z = 11}};

	sphere = (t_sphere) {
						.color = 0xcc0000,
						.diameter = 6,
						.center = (t_vector3) {.x = 0, .y = 0, .z = 2}};

	plane = (t_plane) {
						.color = 0xffff00,
						.center = (t_vector3) {.x = 0, .y = -1, .z = 0},
						.orient = (t_vector3) {.x = 0,
												.y = 1,
												.z = 0}};

	square = (t_square) {
						.color = 0x0000ff,
						.center = (t_vector3) {.x = 0, .y = 0, .z = 0},
						.orient = (t_vector3) {.x = 0, .y = -1, .z = 0},
						.size = 10.0};
	cylinder = (t_cylinder) {
						.color = 0xff0000,
						.center = (t_vector3) {.x = 0, .y = 2, .z = 5},
						.orient = (t_vector3) {.x = 1, .y = 0, .z = 0},
						.diameter = 3,
						.height = 7.0};

	cylinder2 = (t_cylinder) {
			.color = 0x00ffff,
			.center = (t_vector3) {.x = 0, .y = 1, .z = 5},
			.orient = (t_vector3) {.x = 0, .y = 1, .z = 0},
			.diameter = 3,
			.height = 7.0};

	triangle = (t_triangle) {
						.color = 0xffff00,
						.x = (t_vector3) {.x = 0, .y = 20, .z = 0},
						.y = (t_vector3) {.x = 0, .y = 0, .z = 0},
						.z = (t_vector3) {.x = 0, .y = 10, .z = 20}
	};

	figure6 = (t_figure) {.content = &cylinder2, .next = NULL, .label = LABEL_CYLINDER};
    figure5 = (t_figure) {.content = &plane, .next = &figure6, .label = LABEL_PLANE};
//	figure4 = (t_figure) {.content = &triangle, .next = &figure5, .label = LABEL_TRIANGLE};
//	figure3 = (t_figure) {.content = &plane, .next = &figure4, .label = LABEL_PLANE};
//
//	figure2 = (t_figure) {.content = &sphere2, .next = &figure3, .label = LABEL_SPHERE};
	figure1 = (t_figure) {.content = &cylinder, .next = &figure5, .label=LABEL_CYLINDER};
	data.figures = &figure1;




	parse(path);


	init(&data);
	test(&data);
	range = (t_pair_double) {.first = 1.0, .second = INFINITY};
	render(&data, data.cam, &range);
	mlx_put_image_to_window(data.mlx, data.window, data.img, 0, 0);
	bind_hooks(&data);
	mlx_loop(data.mlx);
	return (0);
}