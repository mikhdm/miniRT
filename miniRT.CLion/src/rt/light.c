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

/*
*
* ambient_light - calculates ambient light for a surface with scolor.
*
*/
static int	ambient_light(t_ambience *ambience, int const scolor)
{
	int	acolor;

	acolor = cmultargb(linargb(ambience->color), ambience->intensity);
	return (multargb(acolor, scolor));
}

static int calc_diffuse_light(t_light *light,
				int const scolor, double const dot)
{
	t_light		*curr;
	int 		currcolor;
	int			lightcolor;

	curr = light;
	lightcolor = 0;
	while (curr)
	{
		currcolor = cmultargb(linargb(curr->color), curr->brightness);
		currcolor = multargb(scolor, currcolor);
		currcolor = cmultargb(currcolor, dot);
		lightcolor = addargb(lightcolor, currcolor);
		curr = curr->next;
	}
	return (lightcolor);

}

static int	diffuse_light(t_light *light,
		t_vector3 *point,
		t_vector3 *orient,
		int const scolor)
{
	double		dot;
	double		denom;
	t_vector3	lightvec;
	
	lightvec = diffvec3(&light->center, point);
	dot = dot3(orient, &lightvec);
	if (dot3(orient, &lightvec) < 0.0)
		dot = -1.0 * dot;
	denom = hypotvec3(&lightvec) * hypotvec3(orient);
	return (calc_diffuse_light(light, scolor, dot / denom));
}

int light(t_data *data,
		t_vector3 *point, t_vector3 *orient, int const scolor)
{
	int ambient_color;
	int	diffuse_color;
	
	ambient_color = ambient_light(data->ambience, linargb(scolor));
	diffuse_color = diffuse_light(data->light, point, orient, linargb(scolor));
	return (gammargb(addargb(ambient_color, diffuse_color)));
}