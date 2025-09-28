/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 23:38:19 by rmander           #+#    #+#             */
/*   Updated: 2021/05/09 19:31:41 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "rayop.h"
#include "utils.h"

static int	_trace(t_data *data,
				t_vector3 *dirvec, t_pair_double *range)

int	trace_sphere(t_data *data,
		t_vector3 *dirvec, t_pair_double *range)
{
	double 			closest_step;
	short int		intersected;
	t_vector3		closest_point;
	t_vector3		orient;
	t_pair_double	steps;
	int				color;

	closest_step = INFINITY;
	intersected = FALSE;
	steps = intersect_sphere(data, dirvec, data->figures->sphere);
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
	
	closest_point = calc_ray_point(data, dirvec, closest_step); 
	orient = calc_sphere_orient(&closest_point, data->figures->sphere);

	color = data->figures->sphere->color;
	color = light(data, &closest_point, &orient, color);
	return (color);
}
