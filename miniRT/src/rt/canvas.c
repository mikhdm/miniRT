/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 02:29:22 by rmander           #+#    #+#             */
/*   Updated: 2021/05/01 21:35:48 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "linop.h"
#include "utils.h"
#include <math.h>

t_viewport	calc_viewport(t_data *data)
{
	double		fov_radian;
	t_viewport	viewport;

	fov_radian = deg_to_rad(data->cam->fov / 2);
	viewport.width = 2 * tan(fov_radian);
	viewport.height = data->screen->height * (viewport.width / data->screen->width);
	return (viewport);
}

t_vector3	ft_conv_to_viewport(t_data *data, int x, int y)
{
	t_vector3	dirvec;

	dirvec.x = x * (data->viewport->width / data->screen->width);
	dirvec.y = y * (data->viewport->height / data->screen->height);
	dirvec.z = 1.0; // TODO how to deal with orientation vector of camera?
	return (dirvec);
}

void	ft_putpixel(t_data *data, int x, int y, int color)
{
	char    *dest;
	int		screen_x;
	int		screen_y;

	screen_x = data->screen->width / 2 + x;
	screen_y = data->screen->height / 2 - y;
    dest = data->addr + (screen_y * data->length + screen_x * (data->bpp / 8));
	*(unsigned int*)dest = color;
}
