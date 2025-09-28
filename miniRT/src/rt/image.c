/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 02:29:22 by rmander           #+#    #+#             */
/*   Updated: 2021/04/21 04:43:07 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "linop.h"
#include "figure.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

t_vector3	ft_conv_to_viewport(t_meta *meta, int x, int y)
{
	t_vector3	plane;
	
	/* TODO add FOV dependent logic */
	(void) meta;
	plane.x = x * 1.0 / meta->screen->width;
	plane.y = y * 1.0 / meta->screen->height;
	plane.z = 1.0;
	return (plane);
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
