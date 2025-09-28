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
#include "rayop.h"
#include <math.h>

static int calc_diffuse_light(t_light *spot,
							  int const scolor, double const dot)
{
	int 		color;

	color = linargb(spot->color);
	color = cmultargb(color, spot->brightness);
	color = multargb(color, scolor);
	color = cmultargb(color, dot);
	return (color);
}

static int    ambient_light(t_data *data, int const scolor)
{
	int	acolor;

	acolor = linargb(data->ambience->color);
	acolor = cmultargb(acolor, data->ambience->intensity);
	return (multargb(acolor, scolor));
}

static int	diffuse_light(t_data *data,
						 t_vector3 *point, t_vector3 *orient, int const scolor)
{
	int                     color;
	double		            dot;
	t_vector3               light_vec;
	t_vector3               orient_norm;
	t_pair_double           range;
	t_pair_figure_double    pair_figure_t;
	t_light                 *curr;

	range = (t_pair_double){.first = 1e-2, .second = 1};
	curr = data->light;
	color = COLOR_BLACK;
	while (curr)
	{
		light_vec = diffvec3(&curr->center, point);
		pair_figure_t = intersect_closest(data, point, &light_vec, &range);
		if (pair_figure_t.figure)
		{
			curr = curr->next;
			continue ;
		}
		light_vec = normvec3(&light_vec);
		orient_norm = normvec3(orient);
		dot = fabs(dot3(&orient_norm, &light_vec));
		color = addargb(color, calc_diffuse_light(curr, scolor, dot));
		curr = curr->next;
	}
	return (color);
}

int light(t_data *data,
		t_vector3 *point, t_vector3 *orient, int const scolor)
{
	int ambient_color;
	int diffuse_color;
	int surface_color;

	surface_color = linargb(scolor);
	ambient_color = ambient_light(data, surface_color);
	diffuse_color = diffuse_light(data, point, orient, surface_color);
	return (gammargb(addargb(ambient_color, diffuse_color)));
}