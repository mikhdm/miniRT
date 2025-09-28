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
	t_viewport		viewport;
	t_pair_double	range;
	t_light			lights;
	t_light			light2;
	t_ambience		ambience;
	const char		*labels[NUM_LABELS + 1] = {LABEL_SPHERE, LABEL_PLANE, LABEL_SQUARE, LABEL_CYLINDER,
													LABEL_TRIANGLE, LABEL_CAMERA, LABEL_LIGHT, LABEL_LIGHT,
													LABEL_AMBIENCE, NULL};

	screen = (t_screen) {.width = 1280, .height = 1024, .title = "miniRT"};

	cam = (t_camera) {.center = (t_vector3) {.x = .0, .y = .0, .z = 0.0},
					.orient = (t_vector3) {.x = 0, .y = 0, .z = 1},
					.fov = 60};

	data = (t_data) {.mlx = NULL, .window = NULL, .img = NULL,
					.addr = NULL, .bpp = 0, .length = 0, .endian = 0,
					.screen = &screen, .cam = &cam, .viewport = NULL};
	
	ambience = (t_ambience) {.intensity = 0.8, .color = 0xffffbb};
	
	light2 = (t_light) {.brightness = 1.0, .color = 0xffff00,
					.center = (t_vector3) {.x = -2, .y = 2, .z = 10},
					.next = NULL};
	lights = (t_light) {.brightness = 1.0, .color = 0xffffff,
		.center = (t_vector3) {.x = 2, .y = 3, .z = 2},
		.next = NULL};

	data.light = &lights;
	data.ambience = &ambience;

	viewport = calc_viewport(&data);

	data.viewport = &viewport;

	sphere2 = (t_sphere) {
						.color = 0x0000cc,
						.diameter = 2,
						.center = (t_vector3) {.x = -1, .y = 0, .z = 10}};

	sphere = (t_sphere) {
						.color = 0xffff00,
						.diameter = 2,
						.center = (t_vector3) {.x = 1, .y = 0, .z = 11}};

	plane = (t_plane) {
						.color = 0xffffff,
						.center = (t_vector3) {.x = 0, .y = -2, .z = 1},
						.orient = (t_vector3) {.x = 0,
												.y = 1,
												.z = 0}};

	square = (t_square) {
						.color = 0xff0000,
						.center = (t_vector3) {.x = 0, .y = 2, .z = 20},
						.orient = (t_vector3) {.x = 0, .y = .0, .z = 1},
						.size = 8.0};
	cylinder = (t_cylinder) {
						.color = 0xffff00,
						.center = (t_vector3) {.x = 0, .y = 0, .z = 12},
						.orient = (t_vector3) {.x = -2/sqrt(14), .y = 1/sqrt(14), .z = 3/sqrt(14)},
						.diameter = 3,
						.height = 7.0};

	cylinder2 = (t_cylinder) {
			.color = 0x00ff00,
			.center = (t_vector3) {.x = 0, .y = 0, .z = 12},
			.orient = (t_vector3) {.x = 2/sqrt(14), .y = 1/sqrt(14), .z = 3/sqrt(14)},
			.diameter = 3,
			.height = 7.0};

	triangle = (t_triangle) {
						.color = 0xffffff,
						.x = (t_vector3) {.x = -10, .y = 0, .z = 30},
						.y = (t_vector3) {.x = 10, .y = 0, .z = 30},
						.z = (t_vector3) {.x = 0, .y = 10, .z = 30}
	};

	figure3 = (t_figure) {.content = &plane, .next = NULL, .label = LABEL_PLANE};

	figure2 = (t_figure) {.content = &sphere2, .next = &figure3, .label = LABEL_SPHERE};
	figure1 = (t_figure) {.content = &sphere, .next = &figure2, .label=LABEL_SPHERE};
	data.figures = &figure1;
	init(&data);
	test(&data);
	range = (t_pair_double) {.first = 1.0, .second = INFINITY};
	render(&data, &data.cam->center, &range);
	mlx_put_image_to_window(data.mlx, data.window, data.img, 0, 0);
	bind_hooks(&data);
	mlx_loop(data.mlx);
	return (0);
}