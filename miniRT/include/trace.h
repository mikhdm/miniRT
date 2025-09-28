/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 17:42:13 by rmander           #+#    #+#             */
/*   Updated: 2021/05/09 18:56:19 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

#include "canvas.h"
#include "linop.h"
#include "utils.h"

int		trace_sphere(t_data *data,
			t_vector3 *dirvec, t_pair_double *range);
int		trace_plane(t_data *data,
			t_vector3 *dirvec, t_pair_double *range);
int		trace_square(t_data *data,
			t_vector3 *dirvec, t_pair_double *range);
int		trace_triangle(t_data *data,
			t_vector3 *dirvec, t_pair_double *range);
int		trace_cylinder(t_data *data,
			t_vector3 *dirvec, t_pair_double *range);

#endif
