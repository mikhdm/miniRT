/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 03:46:12 by rmander           #+#    #+#             */
/*   Updated: 2021/06/07 04:29:46 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include <math.h>

int	a_component(int argb)
{
	return ((argb & (0xff << 24)) >> 24);
}

int	r_component(int argb)
{
	return ((argb & (0xff << 16)) >> 16);
}

int	g_component(int argb)
{
	return ((argb & (0xff << 8)) >> 8);
}

int	b_component(int argb)
{
	return (argb & 0xff);
}

int	argb_color(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}
