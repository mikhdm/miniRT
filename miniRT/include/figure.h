/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 02:35:16 by rmander           #+#    #+#             */
/*   Updated: 2021/04/17 03:27:04 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGURE_H
# define FIGURE_H

#include "rt.h"

typedef struct s_sphere
{
	double 	x;
	double 	y;
	double 	z;
	double 	d;
	int		color;
}	t_sphere;

typedef struct s_plane
{
	double 		x;
	double 		y;
	double 		z;
	int			color;
	t_vector3d	orient;
}	t_plane;

typedef struct s_square
{
	double		x;
	double		y;
	double		z;
	double		size;
	int			color;
	t_vector3d	orient;
}	t_square;

typedef struct s_cylinder
{
	double		x;
	double		y;
	double		z;
	double		d;
	double		height;
	int			color;
	t_vector3d	orient;
}	t_cylinder;

typedef struct s_triangle
{
	t_vector3d	x;
	t_vector3d	y;
	t_vector3d	z;
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
