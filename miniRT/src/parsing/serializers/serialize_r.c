/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:35:30 by rmander           #+#    #+#             */
/*   Updated: 2021/06/07 18:15:49 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "utils.h"
#include "parsing/errors.h"
#include "parsing/serialize.h"
#include "libft.h"
#include <errno.h>
#include <unistd.h>

static void	set_screen(t_data *data, char **strs, int *w, int *h)
{
	t_screen	*screen;
	char		*str;
	size_t		strslen;
	size_t		i;

	screen = NULL;
	if (!alloca_to((void **)&screen, sizeof(t_screen)))
		serialize_error(ERROR_ERRNO, errno, data, strs);
	data->screen = screen;
	strslen = ft_strslen(strs);
	if (strslen != 3)
		serialize_error(ERROR_SYNTAX_RESOLUTION, 255, data, strs);
	i = 1;
	while (i < strslen)
	{
		str = strs[i++];
		while (*str)
			if (!ft_isdigit(*str++))
				serialize_error(ERROR_INVALID_RESOLUTION, 255, data, strs);
	}
	*w = ft_atoi(strs[1]);
	*h = ft_atoi(strs[2]);
	*(data->screen) = (t_screen){.width = (int)*w, .height = (int)*h,
		.title = WINDOW_TITLE};
}

t_data	*serialize_r(t_data *data, char **strs)
{
	size_t		w;
	size_t		h;

	if (data->screen)
		serialize_error(ERROR_DUPLICATE_RESOLUTION, 255, data, strs);
	set_screen(data, strs, (int *)&w, (int *)&h);
	if (data->screen->width < 1 || data->screen->height < 1)
		serialize_error(ERROR_INVALID_RESOLUTION, 255, data, strs);
	return (data);
}
