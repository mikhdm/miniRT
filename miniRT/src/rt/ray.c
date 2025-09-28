/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:26:17 by rmander           #+#    #+#             */
/*   Updated: 2021/04/19 02:24:53 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "rt.h"
#include "linop.h"
#include "figure.h"
#include "utils.h"

t_pair_double	ft_intersect_sphere(
					t_meta *meta,
					t_vector3 *distvec,
					t_sphere *sphere)
{
	double			radius;
	t_vector3		sp_cam_vec;
	t_pair_double	values;
	
	radius = sphere->diameter / 2;
	sp_cam_vec = diffvec3(&meta->cam->center, &sphere->center);
	values = calc_quad_equation(
			dot3(distvec, distvec),
			2 * dot3(&sp_cam_vec, distvec),
			dot3(&sp_cam_vec, &sp_cam_vec) - radius * radius);
	return (values);
}

int	ft_trace_sphere(
		t_meta *meta,
		t_vector3 *distvec,
		t_sphere *sphere,
		t_pair_double *steprange)
{
	double 			closest_step = INFINITY;
	t_pair_double	steps;

	steps = ft_intersect_sphere(meta, distvec, sphere);

	/* LOG */
	printf("[%f, %f]\n", steps.first, steps.second);
	/* END LOG */

	if (steprange->first <= steps.first
		&& steps.first <= steprange->second
		&& steps.first < closest_step)
	{
		closest_step = steps.first;
	}
	if (steprange->first <= steps.second
		&& steps.second <= steprange->second
		&& steps.second < closest_step)
	{
		closest_step = steps.second;
	}
	if (isinf(closest_step))
		return (0x0);
	return (sphere->color);

}
