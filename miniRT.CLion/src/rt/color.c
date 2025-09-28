/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 03:46:12 by rmander           #+#    #+#             */
/*   Updated: 2021/05/12 22:32:00 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
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

int	addargb(int argb_left, int argb_right)
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

int	multargb(int argb_left, int argb_right)
{
	int	a;
	int	r;
	int	g;
	int	b;

	a = (a_component(argb_left) * a_component(argb_right)) / 255;
	r = (r_component(argb_left) * r_component(argb_right)) / 255;
	g = (g_component(argb_left) * g_component(argb_right)) / 255;
	b = (b_component(argb_left) * b_component(argb_right)) / 255;
	return (argb_color(a, r, g, b));
}


int	cmultargb(int argb, double const value)
{
	int	a;
	int	r;
	int	g;
	int	b;

	a = (int)(a_component(argb) * value);
	r = (int)(r_component(argb) * value);
	g = (int)(g_component(argb) * value);
	b = (int)(b_component(argb) * value);
	return (argb_color(a, r, g, b));
}

int	linargb(int argb)
{
	int	a;
	int	r;
	int	g;
	int	b;

	a = (int)(pow(a_component(argb) / 255.0, GAMMA_COEF) * 255);
	r = (int)(pow(r_component(argb) / 255.0, GAMMA_COEF) * 255);
	g = (int)(pow(g_component(argb) / 255.0, GAMMA_COEF) * 255);
	b = (int)(pow(b_component(argb) / 255.0, GAMMA_COEF) * 255);
	return (argb_color(a, r, g, b));
}

int	gammargb(int argb)
{
	int	a;
	int	r;
	int	g;
	int	b;

	a = (int)(pow(a_component(argb) / 255.0, GAMMA_REVERSE_COEF) * 255);
	r = (int)(pow(r_component(argb) / 255.0, GAMMA_REVERSE_COEF) * 255);
	g = (int)(pow(g_component(argb) / 255.0, GAMMA_REVERSE_COEF) * 255);
	b = (int)(pow(b_component(argb) / 255.0, GAMMA_REVERSE_COEF) * 255);
	return (argb_color(a, r, g, b));
}
