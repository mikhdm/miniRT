/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 17:13:34 by rmander           #+#    #+#             */
/*   Updated: 2021/05/14 19:52:28 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "canvas.h"
#include "linop.h"
#include <math.h>

/*
*
* ambient_light - calculates ambient light for a surface with scolor.
*
*/
static int	ambient_light(t_ambience *ambience, int const scolor)
{
	int	acolor;

	acolor = linargb(ambience->color);
	acolor = cmultargb(acolor, ambience->intensity);
	return (multargb(acolor, scolor));
}

static int calc_diffuse_light(t_light *light,
				int const scolor, double const dot)
{
	t_light		*curr;
	int 		curr_color;
	int			sum_color;

	curr = light;
	sum_color = COLOR_BACKGROUND;
	while (curr)
	{
		curr_color = linargb(curr->color);
		curr_color = cmultargb(curr_color, curr->brightness);
		curr_color = multargb(curr_color, scolor);
		curr_color = cmultargb(curr_color, dot);
		sum_color = addargb(sum_color, curr_color);
		curr = curr->next;
	}
	return (sum_color);
}

static int	diffuse_light(t_light *light,
		t_vector3 *point,
		t_vector3 *orient,
		int const scolor)
{
	double		dot;
	t_vector3	light_vec;
	t_vector3   orient_norm;
	
	light_vec = diffvec3(&light->center, point);
	light_vec = normvec3(&light_vec);
	orient_norm = normvec3(orient);
	dot = fmax(0.0, dot3(&orient_norm, &light_vec));
	return (calc_diffuse_light(light, scolor, dot));
}

int light(t_data *data,
		t_vector3 *point, t_vector3 *orient, int const scolor)
{
	int ambient_color;
	int	diffuse_color;
	int surface_color;

	surface_color = linargb(scolor);
	ambient_color = ambient_light(data->ambience, surface_color);
	diffuse_color = diffuse_light(data->light, point, orient, surface_color);
	return (gammargb(addargb(ambient_color, diffuse_color)));
}