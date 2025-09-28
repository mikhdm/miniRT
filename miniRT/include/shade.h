/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 23:14:15 by rmander           #+#    #+#             */
/*   Updated: 2021/05/08 23:16:02 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifnder SHADE_H
# define SHADE_H

/*
*
* shade - function calculates color with light and shadows 
* 	on a figure depending on dirvec, t param, and figure. 
*
*/
int	shade(t_data *data,
		t_figure *figure, t_vector3 *dirvec, double t);

#endif
