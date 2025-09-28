/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayop.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:26:17 by rmander           #+#    #+#             */
/*   Updated: 2021/05/10 19:05:57 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "trace.h"
#include "shade.h"
#include "linop.h"
#include "light.h"
#include "utils.h"
#include "libft.h"
#include <math.h>

double	intersect(t_data *data,
			t_vector3 *dirvec, t_figure *figure)
{
	double	t;
	
	t = INFINITY;
	if (ft_strcmp(figure->content->label, LABEL_SPHERE) == 0)
		t = intersect_sphere(data, dirvec, figure->content);
	else if (ft_strcmp(figure->content->label, LABEL_PLANE) == 0)
		t = intersect_plane(data, dirvec, figure->content);
	else if (ft_strcmp(figure->content->label, LABEL_SQUARE) == 0)
		t = intersect_square(data, dirvec, figure->content);
	else if (ft_strcmp(figure->content->label, LABEL_TRIANGLE) == 0)
		t = intersect_triangle(data, dirvec, figure->content);
	else if (ft_strcmp(figure->content->label, LABEL_CYLINDER) == 0)
		t = intersect_cylinder(data, dirvec, figure->content);
	return (t);
}

int	shade(t_data *data,
		t_figure *figure, t_vector3 *dirvec, double t)
{
	int	color;

	color = COLOR_BACKGROUND;
	if (ft_strcmp(figure->content->label, LABEL_SPHERE) == 0)
		color = shade_sphere(data, figure->content, dirvec, t);
	else if (ft_strcmp(figure->content->label, LABEL_PLANE) == 0)
		color = shade_plane(data, figure->content, dirvec, t);
	else if (ft_strcmp(figure->content->label, LABEL_SQUARE) == 0)
		color = shade_square(data, figure->content, dirvec, t);
	else if (ft_strcmp(figure->content->label, LABEL_TRIANGLE) == 0)
		color = shade_triangle(data, figure->content, dirvec, t);
	else if (ft_strcmp(figure->content->label, LABEL_CYLINDER) == 0)
		color = shade_cylinder(data, figure->content, dirvec, t);
	return (color);
}


int	trace(t_data *data,
		t_vector3 *dirvec, t_pair_double *range)
{
	double			t;
	double			min_t;
	t_figure		curr;
	t_figure		figure;

	curr = data->figures;
	min_t = INFINITY;
	while (curr)
	{
		t = intersect(data, dirvec, curr);
		if (t >= range.first && t <= range.second && t < min_t)
		{
			min_t = t;
			figure = curr;
		}
		curr = curr->next;
	}
	if (!isinf(min_t))
		return (COLOR_BACKGROUND);
	return (shade(data, dirvec, figure, min_t));
}
