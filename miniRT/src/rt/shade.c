/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 23:16:08 by rmander           #+#    #+#             */
/*   Updated: 2021/05/09 18:31:45 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "linop.h"
#include "light.h"


int	shade_sphere(t_data *data,
		t_sphere *sphere, t_vector3 *dirvec, double t)
{
	int	color;
	t_vector3	t_mult_dirvec;
	t_vector3	p_hit;

	t_mult_dirvec = cmultvec3(t, dirvec);
	p_hit = sumvec3(&data->cam->center, &t_mult_dirvec);
	orient = calc_sphere_orient(&p_hit, figure->content);
	color = light(data, &p_hit, &orient, figure->content->color);

}

int	shade_triangle(t_data *data,
		t_triangle *triangle, t_vector3 *dirvec, double t)
{
	/* TODO */	
	(void)data;
	(void)triangle;
	(void)dirvec;
	(void)t;
	return (1);
}

int	shade_square(t_data *data,
		t_square *square, t_vector3 *dirvec, double t)
{

}

int shade_plane(t_data *data,
		t_plane *plane, t_vector3 *dirvec, double t)
{

}

int shade_cylinder(t_data *data,
		t_cylinder *cylinder, t_vector3 *dirvec, double t)
{
	/* TODO */	
	(void)data;
	(void)cylinder;
	(void)dirvec;
	(void)t;
	return (1);

}
