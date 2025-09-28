/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:26:17 by rmander           #+#    #+#             */
/*   Updated: 2021/04/18 20:43:49 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"
#include "linop.h"
#include "figure.h"
#include "utils.h"



t_pair_double	ft_intersect_ray(t_meta *meta, t_vector3 *distvec, t_figure *figures)
{
	double radius;
	t_sphere

	/* TODO */
}

int	ft_trace_ray(t_meta *meta, t_vector3 *distvec, t_figure *figures, double tmin, double tmax)
{
	double closest_t = INFINITY;
	t_sphere sphere = figures->sphere;

	/* TODO */
}
