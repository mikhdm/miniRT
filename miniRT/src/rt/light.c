/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 17:13:34 by rmander           #+#    #+#             */
/*   Updated: 2021/04/25 18:05:59 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rt.h"

static double	_calc(t_light *light,
						t_vector3 *point, t_vector3 *orient)
{
	/* TODO */
}

double	light(t_ambience *ambience, t_light *lights,
			t_vector3 *point, t_vector3 *orient)
{
	double intensity;
	t_light *head;

	head = lights;
	intensity = .0;
	if (ambience)
		intencity += ambience->intencity;
	while (head)
	{
		intencity += _calc(head, point, orient); 
		head = head->next;
	}
	return (intencity);
}
