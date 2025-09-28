/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:48:55 by rmander           #+#    #+#             */
/*   Updated: 2021/04/17 22:05:55 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

/*
*
* t_vector3d - structure to store 3D space vector
*
*/
typedef struct s_vector3
{
	double x;
	double y;
	double z;
}	t_vector3;

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
* t_camera - structure to store cam position
*
*/
typedef struct s_camera
{
	double x;
	double y;
	double z;
	double fov;
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
	double		fov;
	t_screen	*screen;
	t_camera	*cam;
}	t_meta;


/*
*
* ft_putpixel - function which put color defined by color param
* into canvas pointed by x and y. Convertation from canvas to screen is done
* automatically.
*
*/
void		ft_putpixel(t_meta *meta, int x, int y, int color);
t_vector3	*ft_conv_to_viewport(t_meta *meta, int x, int y);

#endif
