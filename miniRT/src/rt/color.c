/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 03:46:12 by rmander           #+#    #+#             */
/*   Updated: 2021/04/28 23:40:54 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

int a_component(int argb)
{
	return ((argb & (0xff << 24)) >> 24);
}

int	r_component(int argb)
{
	return ((argb & (0xff << 16)) >> 16);
}

int g_component(int argb)
{
	return ((argb & (0xff << 8)) >> 8);
}

int b_component(int argb)
{
	return (argb & 0xff);
}

int argb_color(int a, int r, int g, int b)
{
	return(a << 24 | r << 16 | g << 8 | b);
}

int	blendargb(int argb_left, int argb_right)
{
	int	a;
	int	r;
	int	g;
	int	b;

	a = (a_component(argb_left) + a_component(argb_right)) / 2;
	r = (r_component(argb_left) + r_component(argb_right)) / 2;
	g = (g_component(argb_left) + g_component(argb_right)) / 2;
	b = (b_component(argb_left) + b_component(argb_right)) / 2;
	return (argb_color(a, r, g, b));
}

int	cmultargb(int argb, double const value)
{
	int	a;
	int	r;
	int	g;
	int	b;

	a = a_component(argb) * value;
	r = r_component(argb) * value;
	g = g_component(argb) * value;
	b = b_component(argb) * value;
	return (argb_color(a, r, g, b));
}
