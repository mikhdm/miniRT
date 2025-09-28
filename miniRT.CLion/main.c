/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:37:11 by rmander           #+#    #+#             */
/*   Updated: 2021/05/14 22:05:52 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "event.h"
#include "render.h"
#include "screenshot.h"
#include "parsing/errors.h"
#include "parsing/parse.h"
#include "mlx.h"
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

static void init(t_data *data, short windowed)
{
	data->mlx = mlx_init();
	data->img = mlx_new_image(
							data->mlx,
							data->screen->width,
							data->screen->height); 
	data->addr = mlx_get_data_addr(
							data->img,
							&data->bpp,
							&data->length,
							&data->endian);
	if (windowed)
		data->window = mlx_new_window(
				data->mlx,
				data->screen->width,
				data->screen->height,
				data->screen->title);
}

static short    processing(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_perror(ERROR_PATH_PARAM_EMPTY);
		exit(255);
	}
	if (argc == 2)
		return (DO_WINDOW);
	if (argc == 3)
	{
		if (ft_strncmp(argv[2], ARGV_SCREENSHOT,
		               imax((ssize_t)ft_strlen(argv[2]),
		                    (ssize_t)ft_strlen(ARGV_SCREENSHOT))) != 0)
		{
			ft_perror(ERROR_SCREENSHOT_PARAM_WRONG);
			exit(255);
		}
		else
			return (DO_SCREENSHOT);
	}
	ft_perror(ERROR_NUM_ARGS_WRONG);
	exit(255);
}

int main(int argc, char **argv)
{
	t_data      *data;
	short       status;

	data = NULL;
	status = processing(argc, argv);
	if (status == DO_SCREENSHOT)
	{
		data = parse(argv[1]);
		init(data, FALSE);
		render(data, data->cam,
		 &((t_pair_double){.first = 1.0, .second = INFINITY}));
		screenshot(data);
		cleanup(data);
	}
	else
	{
		data = parse(argv[1]);
		init(data, TRUE);
		render(data, data->cam,
		       &((t_pair_double){.first = 1.0, .second = INFINITY}));
		mlx_put_image_to_window(data->mlx,
						        data->window,
						        data->img, 0, 0);
		bind_hooks(data);
		mlx_loop(data->mlx);
	}
	return (0);
}