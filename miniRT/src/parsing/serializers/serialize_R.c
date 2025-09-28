/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize_R.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:35:30 by rmander           #+#    #+#             */
/*   Updated: 2021/05/28 18:12:08 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "utils.h"
#include "parsing/errors.h"
#include "parsing/serialize.h"
#include "libft.h"
#include "mlx.h"
#include <errno.h>
#include <unistd.h>

static void set_screen(t_data *data, char **strs, int *w, int *h)
{
	t_screen	*screen;
	char        *str;
	size_t      strslen;
	size_t      i;

	screen = NULL;
	str = NULL;
	if (!alloca_to((void**)&screen, sizeof(t_screen)))
		serialize_exitfree(ERROR_ERRNO, errno, data, strs);
	strslen = ft_strslen(strs);
	if (strslen != 2)
		serialize_exitfree(ERROR_SYNTAX_RESOLUTION, 255, data, strs);
	i = 0;
	while (i < strslen)
	{
		str = strs[i++];
		while (*str)
			if (!ft_isdigit(*str++))
				serialize_exitfree(ERROR_SYNTAX_RESOLUTION, 255, data, strs);
	}
	*w = ft_atoi(strs[0]);
	*h = ft_atoi(strs[1]);
	*screen = (t_screen) {.width = (int)*w, .height = (int)*h, .title="miniRT"};
	data->screen = screen;
}

t_data    *serialize_R(t_data *data, char const *line)
{
	size_t      max_w;
	size_t      max_h;
	size_t      w;
	size_t      h;
	char        **strs;

	strs = NULL;
	max_w = 0;
	max_h = 0;
	mlx_get_screen_size(data->mlx, (int *)&max_w, (int *)&max_h);
	line += ft_strlen(LABEL_RESOLUTION);
	if (!ft_isspace(*line))
		serialize_exitfree(ERROR_SYNTAX_RESOLUTION, 255, data, NULL);
	strs = ft_splitf(line, &ft_isspace);
	if (!strs)
		serialize_exitfree(ERROR_ERRNO, errno, data, NULL);
	set_screen(data, strs, (int*)&w, (int*)&h);
	if ((size_t)data->screen->width > max_w)
		data->screen->width = (int)max_w;
	if ((size_t)data->screen->height > max_h)
		data->screen->height = (int)max_h;
	return (data);
}