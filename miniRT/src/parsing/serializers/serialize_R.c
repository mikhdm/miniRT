/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize_R.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:35:30 by rmander           #+#    #+#             */
/*   Updated: 2021/05/23 20:24:20 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "utils.h"
#include "parsing/errors.h"
#include "libft.h"
#include "mlx.h"
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

void        check_nonspace_sym(t_data *data, char sym, int code, int status)
{
	if (!ft_isspace(sym))
	{
		close(data->fildes);
		ft_pexit(code, status);
		// CLEANUP
	}
}

t_data    *serialize_R(t_data *data, char const *line)
{
	t_screen    *screen;
	size_t      max_w;
	size_t      max_h;
	size_t      w;
	size_t      h;
	char**      strs;

	screen = NULL;
	strs = NULL;
	mlx_get_screen_size(data->mlx, (int *)&max_w, (int *)&max_h);
	if (!alloca_to((void**)&screen, sizeof(t_screen)))
	{
		close(data->fildes);
		exit(ENOMEM);
		// CLEANUP
	}
	check_nonspace_sym(data, *line, ERROR_SYNTAX_RESOLUTION, 255);
	// line = skip_spaces_str(line);
	// w = ft_atoi(line);
	// line = skip_spaces_str(line);
	// h = ft_atoi(line);
	*screen = (t_screen) {.width = (int)w, .height = (int)h, .title="miniRT"};
	data->screen = screen;
	return (data);
}