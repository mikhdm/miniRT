/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 23:14:15 by rmander           #+#    #+#             */
/*   Updated: 2021/06/07 04:29:46 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADE_H
# define SHADE_H

# include "canvas.h"
# include "linop.h"
# include "utils.h"

/*
*
* shade functions are called with actual pair_figure_t data: at the moment
* of call we know figure which are about to be rendered and t value of the ray.
*
*/
int	shade_sphere(t_data *data, t_vector3 *p0, t_vector3 *dirvec,
		t_pair_figure_double *pair_figure_t);
int	shade_plane(t_data *data, t_vector3 *p0, t_vector3 *dirvec,
		t_pair_figure_double *pair_figure_t);
int	shade_square(t_data *data, t_vector3 *p0, t_vector3 *dirvec,
		t_pair_figure_double *pair_figure_t);
int	shade_triangle(t_data *data, t_vector3 *p0, t_vector3 *dirvec,
		t_pair_figure_double *pair_figure_t);
int	shade_cylinder(t_data *data, t_vector3 *p0, t_vector3 *dirvec,
		t_pair_figure_double *pair_figure_t);

#endif
