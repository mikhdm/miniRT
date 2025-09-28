/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayop.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:24:38 by rmander           #+#    #+#             */
/*   Updated: 2021/05/06 21:22:39 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYOP_H
# define RAYOP_H

#include "canvas.h"
#include "linop.h"
#include "utils.h"

t_pair_double	intersect_sphere(t_data *data,
					t_vector3 *distvec, t_sphere *sphere);
double			intersect_plane(t_data *data,
					t_vector3 *dirvec, t_plane *plane);
int				trace_sphere(t_data *data,
					t_vector3 *distvec, t_pair_double *steprange);
int				trace_plane(t_data *data,
					t_vector3 *dirvec, t_pair_double *steprange);
int				trace_square(t_data *data,
					t_vector3 *dirvec, t_pair_double *steprange);

int				trace(t_data *data,
					t_vector3 *dirvec, t_pair_double *range);
#endif
