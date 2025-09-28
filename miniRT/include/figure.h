/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 02:35:16 by rmander           #+#    #+#             */
/*   Updated: 2021/04/19 00:56:41 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGURE_H
# define FIGURE_H

#include "linop.h"

typedef struct s_sphere
{
	int			color;
	double		diameter;
	t_vector3	center;
}	t_sphere;

typedef struct s_plane
{
	int			color;
	t_vector3	center;
	t_vector3	orient;
}	t_plane;

typedef struct s_square
{
	int			color;
	double		size;
	t_vector3	center;
	t_vector3	orient;
}	t_square;

typedef struct s_cylinder
{
	int			color;
	double		diameter;
	double		height;
	t_vector3	center;
	t_vector3	orient;
}	t_cylinder;

typedef struct s_triangle
{
	t_vector3	x;
	t_vector3	y;
	t_vector3	z;
	int			color;
}	t_triangle;

typedef struct s_figure
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_square	*square;
	t_cylinder	*cylinder;
	t_triangle	*triangle;
}	t_figure;

#endif
