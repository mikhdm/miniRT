/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 17:33:26 by rmander           #+#    #+#             */
/*   Updated: 2021/04/25 20:49:33 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

#include "linop.h"

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

#endif
