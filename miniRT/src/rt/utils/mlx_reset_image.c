/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_reset_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:32:33 by rmander           #+#    #+#             */
/*   Updated: 2021/06/03 15:31:14 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "mlx.h"

void	mlx_reset_image(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = NULL;
	data->addr = NULL;
	data->img = mlx_new_image(
			data->mlx,
			data->screen->width,
			data->screen->height);
	data->addr = mlx_get_data_addr(
			data->img,
			&data->bpp,
			&data->length,
			&data->endian);
}
