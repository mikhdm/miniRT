/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayop.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:26:17 by rmander           #+#    #+#             */
/*   Updated: 2021/04/27 04:49:04 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "linop.h"
#include "light.h"
#include "utils.h"
#include "libft.h"
#include "color.h"
#include <math.h>

#include <stdio.h>

t_pair_double	ft_intersect_sphere(t_data *data, t_vector3 *dirvec, t_sphere *sphere)
{
	double			radius;
	t_vector3		sp_cam_vec;
	t_pair_double	values;
	
	radius = sphere->diameter / 2;
	sp_cam_vec = diffvec3(&data->cam->center, &sphere->center);

	values = calc_quad_equation(
			dot3(dirvec, dirvec),
			2 * dot3(dirvec, &sp_cam_vec),
			dot3(&sp_cam_vec, &sp_cam_vec) - pow(radius, 2));
	return (values);
}

int	ft_trace_sphere(t_data *data, t_vector3 *dirvec, t_pair_double *steprange)
{
	double 			closest_step;
	short int		intersected;
	t_vector3		closest_point;
	t_vector3		orient;
	t_pair_double	steps;
	t_vector3		cmult_dirvec;

	closest_step = INFINITY;
	intersected = FALSE;
	steps = ft_intersect_sphere(data, dirvec, data->figures->sphere);
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
	
	cmult_dirvec = cmultvec3(closest_step, dirvec);
	closest_point = sumvec3(&data->cam->center, &cmult_dirvec);
	orient = calc_sphere_orient(&closest_point, data->figures->sphere);

	int color = data->figures->sphere->color; 
	double l = light(data, &closest_point, &orient);

	int a = a_component(color) * l;
	int r = r_component(color) * l;
	int g = g_component(color) * l;
	int b = b_component(color) * l;
	
	return (argb_color(a, r, g, b));
}
