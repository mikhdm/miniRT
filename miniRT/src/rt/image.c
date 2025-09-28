/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 02:29:22 by rmander           #+#    #+#             */
/*   Updated: 2021/04/23 17:02:52 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "rt.h"
#include "linop.h"
#include "figure.h"
#include "utils.h"

t_viewport	calc_viewport(t_meta *meta)
{
	double		fov_radian;
	t_viewport	viewport;

	fov_radian = deg_to_rad(meta->cam->fov / 2);
	viewport.width = 2 * tan(fov_radian);
	viewport.height = meta->screen->height * (viewport.width / meta->screen->width);
	return (viewport);
}

t_vector3	ft_conv_to_viewport(t_meta *meta, int x, int y)
{
	t_vector3	dirvec;

	dirvec.x = x * (meta->viewport->width / meta->screen->width);
	dirvec.y = y * (meta->viewport->height / meta->screen->height);
	dirvec.z = 1.0; // TODO how to deal with orientation vector of camera?
	return (dirvec);
}

void	ft_putpixel(t_meta *meta, int x, int y, int color)
{
	char    *dest;
	int		screen_x;
	int		screen_y;

	screen_x = meta->screen->width / 2 + x;
	screen_y = meta->screen->height / 2 - y;

    dest = meta->addr + (screen_y * meta->length + screen_x * (meta->bpp / 8));
	*(unsigned int*)dest = color;
}
