/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 23:32:05 by rmander           #+#    #+#             */
/*   Updated: 2021/06/07 04:29:46 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "linop.h"
#include "rayop.h"
#include "utils.h"
#include "MLX42/MLX42.h"

void	putpixel(t_data *data, int x, int y, int color)
{
	uint8_t	*dest;
	int		screen_x;
	int		screen_y;

	mlx_image_t *img = (mlx_image_t *)data->img;

	screen_x = data->screen->width / 2 + x;
	screen_y = data->screen->height / 2 - y;
	dest = (img->pixels
			+ (screen_y * img->width + screen_x * (data->bpp / 8)));
	*(unsigned int *)dest = color;
}

void	render(t_data *data, t_camera *cam, t_pair_double *range)
{
	int				x;
	int				y;
	int				color;
	t_vector3		dirvec;

	if (!cam)
		return ;
	y = data->screen->height / 2;
	while (y > -data->screen->height / 2)
	{
		x = -data->screen->width / 2;
		while (x < data->screen->width / 2)
		{
			dirvec = canvas_to_viewport(data, cam, x, y);
			dirvec = look_at(data, cam, &dirvec);
			color = trace(data, &cam->center, &dirvec, range);
			// putpixel(data, x, y, color);
			mlx_put_pixel(data->img, data->screen->width / 2 + x,
				data->screen->height / 2 - y, color);
			++x;
		}
		--y;
	}
}