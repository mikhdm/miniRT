/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 06:51:50 by rmander           #+#    #+#             */
/*   Updated: 2021/06/04 06:53:09 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include <math.h>

int	addrgba(int rgba_left, int rgba_right)
{
    int	r;
    int	g;
    int	b;
    int	a;

    r = (r_component(rgba_left) + r_component(rgba_right)) / 2;
    g = (g_component(rgba_left) + g_component(rgba_right)) / 2;
    b = (b_component(rgba_left) + b_component(rgba_right)) / 2;
    a = (a_component(rgba_left) + a_component(rgba_right)) / 2;
    return (rgba_color(r, g, b, a));
}

int	multrgba(int rgba_left, int rgba_right)
{
    int	r;
    int	g;
    int	b;
    int	a;

    r = (r_component(rgba_left) * r_component(rgba_right)) / 255;
    g = (g_component(rgba_left) * g_component(rgba_right)) / 255;
    b = (b_component(rgba_left) * b_component(rgba_right)) / 255;
    a = (a_component(rgba_left) * a_component(rgba_right)) / 255;
    return (rgba_color(r, g, b, a));
}

int	cmultrgba(int rgba, double const value)
{
    int	r;
    int	g;
    int	b;
    int	a;

    r = (int)(r_component(rgba) * value);
    g = (int)(g_component(rgba) * value);
    b = (int)(b_component(rgba) * value);
    a = (int)(a_component(rgba) * value);
    return (rgba_color(r, g, b, a));
}

int	linrgba(int rgba)
{
    int	r;
    int	g;
    int	b;
    int	a;

    r = (int)(pow(r_component(rgba) / 255.0, GAMMA_COEF) * 255);
    g = (int)(pow(g_component(rgba) / 255.0, GAMMA_COEF) * 255);
    b = (int)(pow(b_component(rgba) / 255.0, GAMMA_COEF) * 255);
    a = (int)(pow(a_component(rgba) / 255.0, GAMMA_COEF) * 255);
    return (rgba_color(r, g, b, a));
}

int	gammrgba(int rgba)
{
    int	r;
    int	g;
    int	b;
    int a;

    r = (int)(pow(r_component(rgba) / 255.0, GAMMA_REVERSE_COEF) * 255);
    g = (int)(pow(g_component(rgba) / 255.0, GAMMA_REVERSE_COEF) * 255);
    b = (int)(pow(b_component(rgba) / 255.0, GAMMA_REVERSE_COEF) * 255);
    a = (int)(pow(a_component(rgba) / 255.0, GAMMA_REVERSE_COEF) * 255);
    return (rgba_color(r, g, b, a));
}
