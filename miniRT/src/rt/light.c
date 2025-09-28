/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 17:13:34 by rmander           #+#    #+#             */
/*   Updated: 2021/04/27 23:47:49 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "canvas.h"
#include "linop.h"
#include <math.h>

static double	_calc(t_light *light,
						t_vector3 *point, t_vector3 *orient)
{
	t_vector3	lightvec;
	double		intensity;
	double		dot;
	double		denominator;
	
	intensity = .0;
	lightvec = diffvec3(&light->center, point);
	dot = fmax(0.0, dot3(orient, &lightvec));
	denominator = hypotvec3(&lightvec) * hypotvec3(orient);
	intensity = light->brightness * dot * pow(denominator, -1);
	return (intensity);
}

double	light(t_data *data,
			t_vector3 *point, t_vector3 *orient)
{
	double	intensity;
	t_light *head;

	head = data->light;
	intensity = .0;
	if (data->ambience)
		intensity += data->ambience->intensity;
	while (head)
	{
		/* TODO how to handle inner light */
		intensity += _calc(head, point, orient);
		head = head->next;
	}
	return (intensity);
}
