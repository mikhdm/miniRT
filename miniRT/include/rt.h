/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:48:55 by rmander           #+#    #+#             */
/*   Updated: 2021/04/17 03:27:16 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

/*
*
* t_meta - structure to store pointers to window, image, etc.
*
 */
typedef	struct s_meta
{
	void		*mlx;
	void		*window;
	void		*img;
    char		*addr;
    int			bpp;
    int         length;
    int         endian;
}	t_meta;

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
* t_vector3d - structure to store 3D space vector
*
*/
typedef struct s_vector3d
{
	double x;
	double y;
	double z;
}	t_vector3d;


void	ft_putpixel(t_meta *meta, int x, int y, int color);

#endif
