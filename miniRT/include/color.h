/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 03:57:38 by rmander           #+#    #+#             */
/*   Updated: 2021/04/29 00:14:45 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

int		a_component(int argb);
int		r_component(int argb);
int		g_component(int argb);
int		b_component(int argb);
int		argb_color(int a, int r, int g, int b);

/*
*
* blendargb - multiply model to blend colors. f(a, b) = a*b.
* a - base color, b - top layer color.
*
*/
int		blendargb(int argb_left, int argb_right);
int		cmultargb(int argb, double const value);

#endif
