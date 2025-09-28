/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayop.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:24:38 by rmander           #+#    #+#             */
/*   Updated: 2021/05/13 23:22:44 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYOP_H
# define RAYOP_H

#include "canvas.h"
#include "linop.h"
#include "utils.h"

double	intersect(t_data *data,
			t_vector3 *dirvec, t_figure *figure);
/*
*
* shade - function calculates color with light and shadows 
* 	on a figure depending on dirvec, t param, and figure. 
*
*/
int		shade(t_data *data,
			t_figure *figure, t_vector3 *dirvec, double t);
int		trace(t_data *data,
			t_vector3 *dirvec, t_pair_double *range);
#endif
