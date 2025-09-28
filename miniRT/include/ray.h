/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:24:38 by rmander           #+#    #+#             */
/*   Updated: 2021/04/19 01:48:11 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

#include "rt.h"
#include "figure.h"
#include "linop.h"
#include "utils.h"

int				ft_trace_sphere(
					t_meta *meta,
					t_vector3 *distvec,
					t_sphere *sphere,
					t_pair_double *steprange);
t_pair_double	ft_intersect_sphere(
					t_meta *meta,
					t_vector3 *distvec,
					t_sphere *sphere);
#endif
