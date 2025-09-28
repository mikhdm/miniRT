/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 03:57:38 by rmander           #+#    #+#             */
/*   Updated: 2021/06/07 04:29:46 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# define GAMMA_COEF 2.2
# define GAMMA_REVERSE_COEF 0.4545

int		a_component(int rgba);
int		r_component(int rgba);
int		g_component(int rgba);
int		b_component(int rgba);
int		rgba_color(int r, int g, int b, int a);
int		linrgba(int rgba);
int		gammrgba(int rgba);
int		addrgba(int rgba_left, int rgba_right);
int		multrgba(int rgba_left, int rgba_right);
int		cmultrgba(int rgba, double value);

#endif
