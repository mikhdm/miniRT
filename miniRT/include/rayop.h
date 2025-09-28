/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayop.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:24:38 by rmander           #+#    #+#             */
/*   Updated: 2021/04/27 20:12:00 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYOP_H
# define RAYOP_H

#include "canvas.h"
#include "linop.h"
#include "utils.h"

t_pair_double	ft_intersect_sphere(t_data *data,
					t_vector3 *distvec, t_sphere *sphere);
double			ft_intersect_plane(t_data *data,
					t_vector3 *dirvec, t_plane *plane);
int				ft_trace_sphere(t_data *data,
					t_vector3 *distvec, t_pair_double *steprange);
int				ft_trace_plane(t_data *data,
					t_vector3 *dirvec, t_pair_double *steprange);
#endif
