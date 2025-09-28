/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:48:55 by rmander           #+#    #+#             */
/*   Updated: 2021/04/25 20:49:34 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

#include "linop.h"
#include "light.h"

/*
*
* t_screen - structure to store screen parameters
*
*/
typedef struct s_screen
{
	int 	width;
	int 	height;
	char*	title;
}	t_screen;

/*
*
* t_plane - structure to store projection plane parameters
*
*/
typedef struct s_viewport
{
	double	width;
	double	height;
}	t_viewport;

/*
*
* t_camera - structure to store cam position
*
*/
typedef struct s_camera
{
	double fov;
	t_vector3 center;
	t_vector3 orient;
}	t_camera;

/*
*
* t_meta - structure to store pointers to window, image, etc.
*
*/
typedef	struct s_meta
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
}	t_meta;

/*
*
* ft_putpixel - function which put color defined by color param
* into canvas pointed by x and y. Convertation from canvas to screen is done
* automatically.
*
*/
void		ft_putpixel(t_meta *meta, int x, int y, int color);

/*
*
*	calc_viewport - calculates width & height of a viewport.
*
*/
t_viewport	calc_viewport(t_meta *meta);
t_vector3	ft_conv_to_viewport(t_meta *meta, int x, int y);

/*
*
* light - calculates intensity of light at point on a surface
* with orientation vector orient.
*
*/
double	light(t_meta *meta,
			t_vector3 *point, t_vector3 *orient);

#endif
