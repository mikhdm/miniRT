/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 17:33:26 by rmander           #+#    #+#             */
/*   Updated: 2021/04/30 04:22:01 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

#include "canvas.h"
#include "linop.h"

typedef struct s_data	t_data;

typedef struct	s_ambience
{
	double		intensity;
	int			color;
}				t_ambience;

typedef struct	s_light
{
	double			brightness;
	int				color;
	t_vector3		center;	
	struct s_light	*next;
}					t_light;

/*
*
* light - calculates intensity of light at point on a surface
* with orientation vector orient.
*
*/
int light(t_data *data,
		t_vector3 *point, t_vector3 *orient, int const scolor);

#endif
