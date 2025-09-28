/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayop.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:24:38 by rmander           #+#    #+#             */
/*   Updated: 2021/04/26 23:08:00 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYOP_H
# define RAYOP_H

#include "canvas.h"
#include "linop.h"
#include "utils.h"

int				ft_trace_sphere(t_data *data,
					t_vector3 *distvec, t_pair_double *steprange);
t_pair_double	ft_intersect_sphere(t_data *data,
					t_vector3 *distvec, t_sphere *sphere);
#endif
