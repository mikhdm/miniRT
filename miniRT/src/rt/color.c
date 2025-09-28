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

int	r_component(int rgba)
{
	return ((rgba >> 24) & 0xff);
}

int	g_component(int rgba)
{
	return ((rgba >> 16) & 0xff);
}

int	b_component(int rgba)
{
	return ((rgba >> 8) & 0xff);
}

int	a_component(int rgba)
{
	return (rgba & 0xff);
}

int	rgba_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
