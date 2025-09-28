/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:42:14 by rmander           #+#    #+#             */
/*   Updated: 2021/05/23 19:03:54 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "canvas.h"
#include "linop.h"
#include <sys/types.h>

typedef struct s_pair_double
{
	double		first;
	double		second;
}	t_pair_double;

typedef struct  s_pair_figure_double {
	t_figure    *figure;
	double      t;
}   t_pair_figure_double;

t_pair_double	calc_quad_equation(double a, double b, double c);
t_vector3		calc_sphere_orient(t_vector3 *point, t_sphere *sphere);
t_vector3       calc_ray_point(t_vector3 *p0, t_vector3 *dirvec, double t);
t_vector3		*gen_square_vertices(t_square *square);
double			deg_to_rad(double deg);
short int		is_polygon_point(t_vector3 *p_hit,
					t_vector3 *vertices, t_vector3 *orient, size_t size);
double			rad_to_deg(double rad);
void			swap_double(double *left, double *right);
short int       alloca_to(void **ptr, size_t size);
double          calc_min_t(t_pair_double values);
t_vector3       calc_triangle_orient(t_triangle *triangle);
double          calc_cylinder_min_t(t_vector3 *p0,
                                    t_pair_double const *values_t,
                                    t_vector3 *dirvec,
                                    t_cylinder *cylinder);
t_vector3       calc_cylinder_orient(t_cylinder *cylinder,
									 t_vector3 *p0,
									 t_vector3 *dirvec,
									 double t);
t_vector3       calc_faceted_orient(t_vector3 *dirvec, t_vector3 *orient);
ssize_t         imax(ssize_t left, ssize_t right);
short           isdir(int fildes);
char      *skip_spaces_str(char *str);

#endif
