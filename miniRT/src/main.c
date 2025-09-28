/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:37:11 by rmander           #+#    #+#             */
/*   Updated: 2021/04/21 04:47:13 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <float.h>
#include <stdio.h>
#include <math.h>
#include "mlx.h"
#include "rt.h"
#include "linop.h"
#include "ray.h" 
#include "event.h"


static void	ft_init(t_meta *meta)
{
	meta->mlx = mlx_init();
	meta->window = mlx_new_window(
							meta->mlx,
							meta->screen->width,
							meta->screen->height,
							meta->screen->title);
	meta->img = mlx_new_image(
							meta->mlx,
							meta->screen->width,
							meta->screen->height); 
	meta->addr = mlx_get_data_addr(
							meta->img,
							&meta->bpp,
							&meta->length,
							&meta->endian);
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
void	quad_equation_test()
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

int main(void)
{
	t_meta		meta;
	t_screen 	screen;
	t_camera	cam;
	t_vector3	*plane;
	t_sphere	sphere;
	
	plane = NULL;
	screen = (t_screen) {.width = 800, .height = 600, .title = "miniRT"};
	cam = (t_camera) {.center = (t_vector3) {.x = .0, .y = .0, .z = 0.0},
					.orient = (t_vector3) {.x = 0, .y = 0, .z = 1}};
	meta = (t_meta) {.mlx = NULL, .window = NULL, .img = NULL,
					.addr = NULL, .bpp = 0, .length = 0, .endian = 0,
					.screen = &screen, .cam = &cam};
	sphere = (t_sphere) {.color = 0xff0000,
						.diameter = 2.8,
						.center = (t_vector3) {.x = 1, .y = 1, .z = 5}};
	ft_init(&meta);
	
	/* LOG */
	printf("bpp: %d;\nline length: %d;\nendian: %d;\n",
		meta.bpp, meta.length, meta.endian); 
	/* END LOG */

	/* TEST */
	linop_test();
	/* END TEST */

	/* TEST */
	quad_equation_test();
	/* END TEST */
	
	int x = -meta.screen->width / 2;
	int y;
	int	color;
	t_vector3 dirvec;
	t_pair_double stepsrange;

	stepsrange = (t_pair_double) {.first = 1.0, .second = INFINITY};
	while (x < meta.screen->width / 2)
	{
		y = -meta.screen->height / 2 + 1;
		while (y < meta.screen->height / 2)
		{
			dirvec = ft_conv_to_viewport(&meta, x, y);
			color = ft_trace_sphere(&meta, &dirvec, &sphere, &stepsrange); 
			ft_putpixel(&meta, x, y, color);
			++y;
		}
		++x;
	}
	
	mlx_hook(meta.window,
		X11_DESTROY_NOTIFY, MASK_NO_EVENT, ft_hook_close, &meta);
	mlx_hook(meta.window,
		X11_KEY_PRESS, MASK_NO_EVENT, ft_hook_keypress, &meta);
	mlx_put_image_to_window(meta.mlx, meta.window, meta.img, 0, 0);
	mlx_loop(meta.mlx);
	return (0);
}
