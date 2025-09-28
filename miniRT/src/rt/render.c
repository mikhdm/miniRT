/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 23:32:05 by rmander           #+#    #+#             */
/*   Updated: 2021/05/10 18:56:01 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "linop.h"
#include "rayop.h"
#include "utils.h"

void	render(t_data *data, t_pair_double *range)
{
	int				x;
	int				y;
	int				color;
	t_vector3		dirvec;

	y = data->screen->height / 2;
	while (y > -data->screen->height / 2)
	{
		x = -data->screen->width / 2;
		while (x < data->screen->width / 2)
		{
			dirvec = conv_to_viewport(data, x, y);
			color = trace(data, &dirvec, range);
			putpixel(data, x, y, color);
			++x;
		}
		--y;
	}
}
