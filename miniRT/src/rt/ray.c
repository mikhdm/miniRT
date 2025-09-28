/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:26:17 by rmander           #+#    #+#             */
/*   Updated: 2021/04/25 20:04:20 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <float.h>
#include <stdio.h>
#include "libft.h"
#include "rt.h"
#include "linop.h"
#include "figure.h"
#include "utils.h"
#include "light.h"

t_pair_double	ft_intersect_sphere(
					t_meta *meta,
					t_vector3 *dirvec,
					t_sphere *sphere)
{
	double			radius;
	t_vector3		sp_cam_vec;
	t_pair_double	values;
	
	radius = sphere->diameter / 2;
	sp_cam_vec = diffvec3(&meta->cam->center, &sphere->center);

	values = calc_quad_equation(
			dot3(dirvec, dirvec),
			2 * dot3(dirvec, &sp_cam_vec),
			dot3(&sp_cam_vec, &sp_cam_vec) - pow(radius, 2));
	return (values);
}

int	ft_trace_sphere(
		t_meta *meta,
		t_vector3 *dirvec,
		t_sphere *sphere,
		t_pair_double *steprange)
{
	double 			closest_step;
	short int		intersected;
	t_vector3		closest_point;
	t_vector3		orient;
	t_pair_double	steps;

	closest_step = INFINITY;
	intersected = FALSE;
	steps = ft_intersect_sphere(meta, dirvec, sphere);
	if (steps.first >= steprange->first && steps.first <= steprange->second
		&& steps.first < closest_step)
	{
		closest_step = steps.first;
		intersected = TRUE;
	}
	if (steps.second >= steprange->first && steps.second <= steprange->second
		&& steps.second < closest_step)
	{
		closest_step = steps.second;
		intersected = TRUE;
	}
	if (intersected == FALSE)
		return (0x0);
	closest_point = sumvec3(&meta->cam->center,
						cmultvec3((double const)closest_step, dirvec));
	orient = calc_sphere_orient(&closest_point, sphere);
	return (sphere->color * light(meta, &closest_point, &orient));
}
