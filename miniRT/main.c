/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:37:11 by rmander           #+#    #+#             */
/*   Updated: 2021/05/30 16:13:23 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "event.h"
#include "render.h"
#include "screenshot.h"
#include "parsing/errors.h"
#include "parsing/parse.h"
#include "libft.h"
#include "mlx.h"
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

static short    check(int argc, char **argv)
{
	char *p;

	p = NULL;
	if (argc == 1)
		ft_pexit(ERROR_PATH_PARAM_EMPTY, 255);
	if (argc == 2 || argc == 3)
	{
		p = ft_strrchr(argv[1], '.');
		if ((!p) || (ft_strncmp(p, ".rt", ft_max((ssize_t)ft_strlen(p), 3)) != 0))
			ft_pexit(ERROR_SCENE_EXT_WRONG, 255);
		if (argc == 3)
		{
			if (ft_strncmp(argv[2], ARGV_SCREENSHOT,
			               ft_max((ssize_t) ft_strlen(argv[2]),
			                    (ssize_t) ft_strlen(ARGV_SCREENSHOT))) != 0)
				ft_pexit(ERROR_SCREENSHOT_PARAM_WRONG, 255);
			else
				return (DO_SCREENSHOT);
		}
		return (DO_WINDOW);
	}
	ft_perror(ERROR_NUM_ARGS_WRONG);
	exit(255);
}

int main(int argc, char **argv)
{
	t_data          *data;
	t_pair_double   range;
	short           status;

	data = NULL;
	status = check(argc, argv);
	range = (t_pair_double){.first = 1.0, .second = INFINITY};
	if (status == DO_SCREENSHOT)
	{
		data = parse(argv[1]);
		init(data, FALSE);
		render(data, data->cam, &range);
		screenshot(data, "screenshot.bmp");
		cleanup(data);
	}
	else
	{
		data = parse(argv[1]);
		init(data, TRUE);
		render(data, data->cam, &range);
		mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
		bind_hooks(data);
		mlx_loop(data->mlx);
		/* TODO cleanup */
	}
	return (0);
}