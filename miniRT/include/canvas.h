/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:48:55 by rmander           #+#    #+#             */
/*   Updated: 2021/04/26 22:34:01 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

#include "linop.h"
#include "light.h"

typedef struct	s_screen
{
	int			width;
	int			height;
	char*		title;
}				t_screen;

typedef struct	s_viewport
{
	double		width;
	double		height;
}				t_viewport;

typedef struct 		s_camera
{
	double 			fov;
	t_vector3 		center;
	t_vector3 		orient;
	struct s_camera	*next;
}					t_camera;

typedef struct		s_sphere
{
	int				color;
	double			diameter;
	t_vector3		center;
	struct s_sphere	*next;
}					t_sphere;

typedef struct		s_plane
{
	int				color;
	t_vector3		center;
	t_vector3		orient;
	struct s_plane	*next;
}					t_plane;

typedef struct		s_square
{
	int				color;
	double			size;
	t_vector3		center;
	t_vector3		orient;
	struct s_square	*next;
}					t_square;

typedef struct			s_cylinder
{
	int					color;
	double				diameter;
	double				height;
	t_vector3			center;
	t_vector3			orient;
	struct s_cylinder	*next; 
}						t_cylinder;

typedef struct			s_triangle
{
	t_vector3			x;
	t_vector3			y;
	t_vector3			z;
	int					color;
	struct s_triangle	*next;
}						t_triangle;

typedef struct	s_figure
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_square	*square;
	t_cylinder	*cylinder;
	t_triangle	*triangle;
}				t_figure;

/*
*
* t_data - structure to store all parsed data & window meta information.
*
*/
typedef	struct s_data
{
    int			bpp;
    int         length;
    int         endian;
    char		*addr;
	void		*mlx;
	void		*window;
	void		*img;
	t_screen	*screen;
	t_viewport	*viewport;
	t_camera	*cam;
	t_light		*light;
	t_ambience	*ambience;
	t_figure	*figures;
}				t_data;

/*
*
* ft_putpixel - function which put color defined by color param
* into canvas pointed by x and y. Convertation from canvas to screen is done
* automatically.
*
*/
void		ft_putpixel(t_data *data, int x, int y, int color);

/*
*
*	calc_viewport - calculates width & height of a viewport.
*
*/
t_viewport	calc_viewport(t_data *data);
t_vector3	ft_conv_to_viewport(t_data *data, int x, int y);

#endif
