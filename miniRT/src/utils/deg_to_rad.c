/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deg_to_rad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:24:55 by rmander           #+#    #+#             */
/*   Updated: 2021/04/23 15:28:42 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double	deg_to_rad(double deg)
{
	return (deg * M_PI * pow(180, -1));
}

double rad_to_deg(double rad)
{
	return (rad * 180 * pow(M_PI, -1));
}
