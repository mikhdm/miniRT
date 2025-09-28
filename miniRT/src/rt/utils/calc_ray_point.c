/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_ray_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 19:26:57 by rmander           #+#    #+#             */
/*   Updated: 2021/05/09 19:31:35 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "linop.h"

t_vector3	calc_ray_point(t_data *data, t_vector3 *dirvec, double t)
{
	t_vector3	t_mult_dirvec;
	t_vector3	point;
	
	t_mult_dirvec = cmultvec3(t, dirvec);
	point = sumvec3(&data->cam->center, &t_mult_dirvec);
	return (point);
}
