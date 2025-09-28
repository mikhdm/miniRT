/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 02:29:22 by rmander           #+#    #+#             */
/*   Updated: 2021/06/04 07:11:41 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "linop.h"
#include "utils.h"
#include "mlx.h"
#include <math.h>
#include <stdlib.h>
#include <errno.h>

t_viewport	calc_viewport(t_data *data, t_camera *cam)
{
	t_viewport	viewport;

	viewport.width = 2 * tan(deg_to_rad(cam->fov * pow (2, -1)));
	viewport.height = (data->screen->height
			* (viewport.width * pow(data->screen->width, -1)));
	return (viewport);
}

/*
*
* canvas_to_viewport - camera position independent ray direction calc.
*
*/
t_vector3	canvas_to_viewport(t_data *data, t_camera *cam, int x, int y)
{
	t_vector3	dirvec;
	double		scale;

	scale = tan(deg_to_rad(cam->fov * pow (2, -1)));
	dirvec.x = x * (cam->viewport->width * pow(data->screen->width, -1));
	dirvec.y = y * (cam->viewport->height * pow(data->screen->height, -1));
	dirvec.z = cam->viewport->height * pow(2, -1) * pow(scale, -1);
	return (normvec3(&dirvec));
}

void	init(t_data *data, short windowed)
{
	data->mlx = mlx_init();
	data->img = mlx_new_image(
			data->mlx,
			data->screen->width,
			data->screen->height);
	data->addr = mlx_get_data_addr(
			data->img,
			&data->bpp,
			&data->length,
			&data->endian);
	if (windowed)
		data->window = mlx_new_window(
				data->mlx,
				data->screen->width,
				data->screen->height,
				data->screen->title);
}

void	putpixel(t_data *data, int x, int y, int color)
{
	char	*dest;
	int		screen_x;
	int		screen_y;

	screen_x = data->screen->width / 2 + x;
	screen_y = data->screen->height / 2 - y;
	dest = (data->addr
			+ (screen_y * data->length + screen_x * (data->bpp / 8)));
	*(unsigned int *)dest = color;
}
