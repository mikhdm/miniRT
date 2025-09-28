/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 23:24:49 by rmander           #+#    #+#             */
/*   Updated: 2021/06/04 05:17:23 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_H
# define INTERSECT_H

# include "canvas.h"
# include "linop.h"
# include "utils.h"

double	intersect_plane(t_vector3 *p0, t_vector3 *dirvec, t_plane *plane);
double	intersect_triangle(t_vector3 *p0, t_vector3 *dirvec,
			t_triangle *triangle);
double	intersect_square(t_vector3 *p0, t_vector3 *dirvec, t_square *square);
double	intersect_sphere(t_vector3 *p0, t_vector3 *dirvec, t_sphere *sphere);
double	intersect_cylinder(t_vector3 *p0, t_vector3 *dirvec,
			t_cylinder *cylinder);

#endif 
