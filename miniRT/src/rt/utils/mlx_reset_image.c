/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_reset_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:32:33 by rmander           #+#    #+#             */
/*   Updated: 2021/06/04 02:37:47 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "mlx.h"

void	mlx_reset_image(t_data *data)
{
	if (!data->mlx)
		return ;
	if (data->img)
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
