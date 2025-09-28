/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 17:13:34 by rmander           #+#    #+#             */
/*   Updated: 2021/04/25 20:45:09 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "rt.h"
#include "linop.h"

static double	_calc(t_light *light,
						t_vector3 *point, t_vector3 *orient)
{
	t_vector3	lightvec;
	double		intensity;
	double		dot;
	
	intensity = .0;
	lightvec = diffvec3(&light->center, point);
	dot = dot3(orient, &lightvec);
	intensity = light->intensity * dot / (hypotvec3(&lightvec) * hypotvec3(orient));
	return (intensity);
}

double	light(t_meta *meta,
			t_vector3 *point, t_vector3 *orient)
{
	double	intensity;
	double	curr;	
	t_light *head;

	head = meta->light;
	intensity = .0;
	curr = .0;
	if (meta->ambience)
		intensity += meta->ambience->intensity;
	while (head)
	{
		curr = _calc(head, point, orient);
		/* TODO how to handle inner light */
		if (curr > 0)
			intensity += curr;
		head = head->next;
	}
	return (intensity);
}
