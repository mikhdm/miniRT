/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 17:33:26 by rmander           #+#    #+#             */
/*   Updated: 2021/04/25 17:56:38 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

typedef struct s_ambience
{
	double	intensity;
	int		color;
}	t_ambience;

typedef struct s_light
{
	double			intensity;
	int				color;
	struct s_light	*next;
	t_vector3		center;	
}	t_light;

/*
*
* light - calculates intensity of light at point on a surface
* with orientation vector orient.
*
*/
double		light(t_ambience *ambience,
				t_light *lights, t_vector3 *point, t_vector3 *orient);

#endif
