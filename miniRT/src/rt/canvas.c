/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 02:29:22 by rmander           #+#    #+#             */
/*   Updated: 2021/05/06 20:49:41 by rmander          ###   ########.fr       */
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
	viewport.height = data->screen->height * (viewport.width * pow(data->screen->width, -1));
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
	double scale;

	scale = tan(deg_to_rad(cam->fov * pow (2, -1)));
	dirvec.x = x * (cam->viewport->width * pow(data->screen->width, -1));
	dirvec.y = y * (cam->viewport->height * pow(data->screen->height, -1));
	dirvec.z = cam->viewport->height * pow(2, -1) * pow(scale, -1);
	return (normvec3(&dirvec));
}

static void set_rot_mat(double *rot[3], t_vector3 *right, t_vector3 *up, t_camera *cam)
{
	rot[0][0] = right->x;
	rot[1][0] = right->y;
	rot[2][0] = right->z;
	rot[0][1] = up->x;
	rot[1][1] = up->y;
	rot[2][1] = up->z;
	rot[0][2] = cam->orient.x;
	rot[1][2] = cam->orient.y;
	rot[2][2] = cam->orient.z;
}

t_vector3   look_at(t_camera *cam, t_vector3 *dirvec)
{
	t_vector3   tmp;
	t_vector3   right;
	t_vector3   up;
	t_vector3   rot_dirvec;
	double      *rot[3];

	rot[0] = malloc(sizeof(double) * 3);
	rot[1] = malloc(sizeof(double) * 3);
	rot[2] = malloc(sizeof(double) * 3);
	if (!(rot[0] && rot[1] && rot[2]))
		exit(ENOMEM);
	tmp = (t_vector3){.x = 0, .y = 100, .z = 0};
	if (!iscollinvec3(&tmp, &cam->orient))
	{
		right = cross3(&tmp, &cam->orient);
		up = cross3(&cam->orient, &right);
	}
	else
	{
		tmp = (t_vector3){.x = -100, .y = 0, .z = 0};
		up = cross3(&tmp, &cam->orient);
		right = cross3(&up, &cam->orient);
	}
	up = normvec3(&up);
	right = normvec3(&right);
	set_rot_mat(rot, &right, &up, cam);
	rot_dirvec = mat33multvec3(rot, dirvec);
	free(*rot);
	return (rot_dirvec);
}

void    init(t_data *data, short windowed)
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
	char    *dest;
	int		screen_x;
	int		screen_y;

	screen_x = data->screen->width / 2 + x;
	screen_y = data->screen->height / 2 - y;
    dest = data->addr + (screen_y * data->length + screen_x * (data->bpp / 8));
	*(unsigned int*)dest = color;
}
