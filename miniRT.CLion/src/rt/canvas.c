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
#include <math.h>

t_viewport	calc_viewport(t_data *data, t_camera *cam)
{
	double		fov_radian;
	t_viewport	viewport;

	fov_radian = deg_to_rad(cam->fov * pow (2, -1));
	viewport.width = 2 * tan(fov_radian);
	viewport.height = data->screen->height * (viewport.width * pow(data->screen->width, -1));
	return (viewport);
}

t_vector3	conv_to_viewport(t_data *data, t_camera *cam, int x, int y)
{
	t_vector3	dirvec;

	dirvec.x = x * (cam->viewport->width * pow(data->screen->width, -1));
	dirvec.y = y * (cam->viewport->height * pow(data->screen->height, -1));
	dirvec.z = 1.0;
	return (dirvec);
}

t_vector3   look_at(t_data *data, t_camera *cam)
{
	t_vector3   tmp;
	t_vector3   right;
	t_vector3   up;
	double      rot[4][4];

	tmp = (t_vector3){.x = 0, .y = 100, .z = 0};
	if (iscollinvec3(&tmp, &cam->orient))
		tmp = (t_vector3){.x = 0, .y = 0, .z = -100};
	right = cross3(&cam->orient, &tmp);
	up = cross3(&right, &cam->orient);
	rot[0] = {cam->orient.x, cam->orient.y, cam->orient.z, 0};
//	rot[0] = (rot[4][4]){
//		{cam->orient.x, cam->orient.y, cam->orient.z, 0},
//		{cam->orient.x, cam->orient.y, cam->orient.z, 0},
//		{cam->orient.x, cam->orient.y, cam->orient.z, 0},
//		{cam->center.x, cam->center.y, cam->center.z, 1}
//	};

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
