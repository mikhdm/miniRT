/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 02:29:22 by rmander           #+#    #+#             */
/*   Updated: 2021/04/17 22:05:54 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>
#include <stdio.h>


t_vector3	*ft_conv_to_viewport(t_meta *meta, int x, int y)
{
	t_vector	*plane;

	plane = malloc(sizeof(t_vector3));
	if (!plane)
		return (NULL);
	plane->x = x * 1.0;
	plane->y = y * 1.0;
	plane->z = 0.0;
	return (plane);
}

void	ft_putpixel(t_meta *meta, int x, int y, int color)
{
	char    *dest;
	int		screen_x;
	int		screen_y;

	screen_x = meta->screen->width / 2 + x;
	screen_y = meta->screen->height / 2 - y;

	/* LOG */
	printf("(%d, %d)\n", screen_x, screen_y);
	/* END LOG */

    dest = meta->addr + (screen_y * meta->length + screen_x * (meta->bpp / 8));
	*(unsigned int*)dest = color;
}
