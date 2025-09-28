/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:37:11 by rmander           #+#    #+#             */
/*   Updated: 2021/04/29 02:54:27 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "linop.h"
#include "rayop.h" 
#include "event.h"
#include "color.h"
#include "utils.h"
#include "mlx.h"
#include <stdlib.h>
#include <math.h>

#include <stdio.h>

static void	ft_init(t_data *data)
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

static void	ft_bind_hooks(t_data *data)
{
	mlx_hook(data->window,
		X11_DESTROY_NOTIFY, MASK_NO_EVENT, &ft_hook_close, &data);
	mlx_hook(data->window,
		X11_KEY_PRESS, MASK_NO_EVENT, &ft_hook_keypress, &data);
}

static void render_sphere(t_data *data, t_pair_double *stepsrange)
{
	int				x;
	int				y;
	int				color;
	t_vector3		dirvec;

	// TODO check zero inclusion due to canvas coordinate system
	y = -data->screen->height / 2 + 1;
	while (y < data->screen->height / 2)
	{
		x = -data->screen->width / 2;
		while (x < data->screen->width / 2)
		{
			dirvec = ft_conv_to_viewport(data, x, y);
			color = ft_trace_sphere(data, &dirvec, stepsrange);
			ft_putpixel(data, x, y, color);
			++x;
		}
		++y;
	}
}

static void	render_plane(t_data *data, t_pair_double *stepsrange)
{
	int				x;
	int				y;
	int				color;
	t_vector3		dirvec;

	// TODO check zero inclusion due to canvas coordinate system
	y = -data->screen->height / 2 + 1;
	while (y < data->screen->height / 2)
	{
		x = -data->screen->width / 2;
		while (x < data->screen->width / 2)
		{
			dirvec = ft_conv_to_viewport(data, x, y);
			color = ft_trace_plane(data, &dirvec, stepsrange);
			ft_putpixel(data, x, y, color);
			++x;
		}
		++y;
	}
}

/* TESTFUNC */
void	linop_test(void)
{
	t_vector3 vec1 = (t_vector3) {.x = 4.0, .y = 1.0, .z = 1.0};
	t_vector3 vec2 = (t_vector3) {.x = -1.0, .y = 2.0, .z = 20.0};

	t_vector3 vec3 = diffvec3(&vec1, &vec2);
	printf("difference: (%f, %f, %f) - (%f, %f, %f) = (%f, %f, %f)\n", 
		vec1.x, vec1.y, vec1.z, vec2.x, vec2.y, vec2.z, vec3.x, vec3.y, vec3.z);

	double scalar = dot3(&vec1, &vec2);
	printf("dot: <(%f, %f, %f), (%f, %f, %f)> = %f\n", 
		vec1.x, vec1.y, vec1.z, vec2.x, vec2.y, vec2.z, scalar);

	t_vector3 vec4 = sumvec3(&vec1, &vec2);
	printf("sum: (%f, %f, %f) + (%f, %f, %f) = (%f, %f, %f)\n", 
		vec1.x, vec1.y, vec1.z, vec2.x, vec2.y, vec2.z, vec4.x, vec4.y, vec4.z);
	
	t_vector3 vec5 = cmultvec3(scalar, &vec1);
	printf("mult by constant: %f * (%f, %f, %f) = (%f, %f, %f) \n",
		scalar, vec1.x, vec1.y, vec1.z, vec5.x, vec5.y, vec5.z); 
}
/* END TESTFUNC */

/* TESTFUNC */
void	quad_equation_test(void)
{
	t_pair_double vals1 = calc_quad_equation(1, 2, 1);
	printf("x^2 + 2*x + 1 = 0 : x1 = %f, x2 = %f\n", vals1.first, vals1.second);

	/* inf test */
	t_pair_double vals2 = calc_quad_equation(1, 2, 3);
	printf("x^2 + 2*x + 3 = 0 : x1 = %f, x2 = %f\n", vals2.first, vals2.second);

	t_pair_double vals3 = calc_quad_equation(1, 2, -3);
	printf("x^2 + 2*x - 3 = 0 : x1 = %f, x2 = %f\n", vals3.first, vals3.second);
}
/* END TESTFUNC */

/* TESTFUNC */
void	deg_to_rad_test(void)
{
	double deg = 180;
	double deg2 = 90;
	printf("%f degrees in radians = %f\n", deg, deg_to_rad(deg)); 
	printf("%f degrees in radians = %f\n", deg2, deg_to_rad(deg2)); 
}
/* END TESTFUNC */

/* TESTFUNC */
void	calc_viewport_test(t_data *data)
{
	t_viewport	viewport;

	viewport = calc_viewport(data);
	printf("projection plane width = %f, height = %f\n", viewport.width, viewport.height);
}
/* END TESTFUNC */

int main(void)
{
	t_data			data;
	t_screen		screen;
	t_camera		cam;
	t_sphere		sphere;
	t_sphere		sphere2;
	t_plane			plane;
	t_figure		figures;
	t_viewport		viewport;
	t_pair_double	stepsrange;
	t_light			lights;
	t_ambience		ambience;
	
	screen = (t_screen) {.width = 800, .height = 600, .title = "miniRT"};

	cam = (t_camera) {.center = (t_vector3) {.x = .0, .y = .0, .z = 0.0},
					.orient = (t_vector3) {.x = 0, .y = 0, .z = 1},
					.fov = 60};

	data = (t_data) {.mlx = NULL, .window = NULL, .img = NULL,
					.addr = NULL, .bpp = 0, .length = 0, .endian = 0,
					.screen = &screen, .cam = &cam, .viewport = NULL};
	
	ambience = (t_ambience) {.intensity = 0.1, .color = 0xd1d1d1};
	lights = (t_light) {.brightness = 0.9, .color = 0xffffff,
		.center = (t_vector3) {.x = 0, .y = 20, .z = 1},
		.next = NULL
	};

	data.light = &lights;
	data.ambience = &ambience;

	viewport = calc_viewport(&data);

	data.viewport = &viewport;

	sphere2 = (t_sphere) {.color = 0x00ff00,
						.diameter = 2,
						.center = (t_vector3) {.x = 0, .y = 0.5, .z = 10},
						.next = NULL};

	sphere = (t_sphere) {.color = 0x0000ff,
						.diameter = 5,
						.center = (t_vector3) {.x = 0, .y = 0, .z = 15},
						.next = &sphere2};

	plane = (t_plane) {.color = 0xff00ff,
						.center = (t_vector3) {.x = 0, .y = 0, .z = 6},
						.orient = (t_vector3) {.x = 0,
												.y = 5/sqrt(50),
												.z = 5/sqrt(50)},
						.next = NULL};

	figures = (t_figure) {.sphere = &sphere,
							.plane = &plane,
							.cylinder = NULL,
							.triangle = NULL,
							.square = NULL};
	data.figures = &figures;

	stepsrange = (t_pair_double) {.first = 1.0, .second = INFINITY};

	ft_init(&data);
	
	/* LOG */
	printf("bpp: %d;\nline length: %d;\nendian: %d;\n",
		data.bpp, data.length, data.endian); 
	/* END LOG */

	/* TEST */
	linop_test();
	/* END TEST */

	/* TEST */
	quad_equation_test();
	/* END TEST */

	/* TEST */
	deg_to_rad_test();
	/* END TEST */

	/* TEST */
	calc_viewport_test(&data);
	/* END TEST */

	(void) render_plane(&data, &stepsrange);
	(void) render_sphere;

	mlx_put_image_to_window(data.mlx, data.window, data.img, 0, 0);
	ft_bind_hooks(&data);
	mlx_loop(data.mlx);
	return (0);
}
