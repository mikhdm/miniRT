/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 17:13:34 by rmander           #+#    #+#             */
/*   Updated: 2021/06/07 16:05:46 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "canvas.h"
#include "linop.h"
#include "rayop.h"
#include <math.h>

static int	calc_d_light(t_light *spot, t_vector3 *orient,
				t_vector3 *lightvec, int const scolor)
{
	int	color;

	color = linrgba(spot->color);
	color = cmultrgba(color, spot->brightness);
	color = multrgba(color, scolor);
	color = cmultrgba(color, fmax(0.0, dot3(orient, lightvec)));
	return (color);
}

static int	ambient_light(t_data *data, int const scolor)
{
	int	acolor;

	acolor = linrgba(data->ambience->color);
	acolor = cmultrgba(acolor, data->ambience->intensity);
	return (multrgba(acolor, scolor));
}

static int	diffuse_light(t_data *data,
				t_vector3 *point, t_vector3 *orient, int const scolor)
{
	int						color;
	t_light					*curr;
	t_vector3				p_shadow;
	t_pair_figure_double	pair_figure_t;
	t_vector3				lightvec;

	curr = data->light;
	color = COLOR_BLACK;
	while (curr)
	{
		lightvec = diffvec3(&curr->center, point);
		p_shadow = cmultvec3(1e-4, &lightvec);
		p_shadow = sumvec3(point, &p_shadow);
		pair_figure_t = intersect_closest(data, &p_shadow, &lightvec,
				&((t_pair_double){1e-4, 1}));
		if (pair_figure_t.figure)
		{
			curr = curr->next;
			continue ;
		}
		lightvec = normvec3(&lightvec);
		color = addrgba(color, calc_d_light(curr, orient, &lightvec, scolor));
		curr = curr->next;
	}
	return (color);
}

int	light(t_data *data,
		t_vector3 *point, t_vector3 *orient, int const scolor)
{
	int	ambient_color;
	int	diffuse_color;
	int	surface_color;

	surface_color = linrgba(scolor);
	ambient_color = ambient_light(data, surface_color);
	diffuse_color = diffuse_light(data, point, orient, surface_color);
	return (gammrgba(addrgba(ambient_color, diffuse_color)));
}
