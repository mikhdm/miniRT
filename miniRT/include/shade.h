/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 23:14:15 by rmander           #+#    #+#             */
/*   Updated: 2021/05/13 23:38:13 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADE_H
# define SHADE_H

#include "canvas.h"
#include "linop.h"

int	shade_sphere(t_data *data,
		t_sphere *sphere, t_vector3 *dirvec, double t);
int shade_plane(t_data *data,
		t_plane *plane, t_vector3 *dirvec, double t);
int	shade_square(t_data *data,
		t_square *square, t_vector3 *dirvec, double t);
int	shade_triangle(t_data *data,
		t_triangle *triangle, t_vector3 *dirvec, double t);
int shade_cylinder(t_data *data,
		t_cylinder *cylinder, t_vector3 *dirvec, double t);

#endif
