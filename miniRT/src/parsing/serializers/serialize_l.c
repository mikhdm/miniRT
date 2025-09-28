/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 04:01:17 by rmander           #+#    #+#             */
/*   Updated: 2021/05/31 16:38:35 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "utils.h"
#include "parsing/serialize.h"
#include "parsing/errors.h"
#include "parsing/validate.h"
#include "libft.h"
#include <stddef.h>
#include <errno.h>

static void	lst_light_append(t_light **head, t_light *new)
{
	t_light	**curr;

	curr = head;
	if (!*curr)
		*curr = new;
	else
	{
		while ((*curr)->next)
			curr = &((*head)->next);
		(*curr)->next = new;
	}
}

static void	set_point(t_data *data, char **strs, char **strs_point,
					  t_light **light)
{
	size_t strslen;

	strslen = ft_strslen(strs_point);
	if (strslen != 3)
	{
		ft_strsfree(strs_point);
		serialize_error(ERROR_SYNTAX_LIGHT, 255, data, strs);
	}
	if (!valid_point3((const char **)strs_point, strslen, &((*light)->center)))
	{
		ft_strsfree(strs_point);
		serialize_error(ERROR_INVALID_LIGHT, 255, data, strs);
	}
	ft_strsfree(strs_point);
}

static void set_light(t_data *data, char **strs, t_light *light)
{
	char **strs_point;
	char **strs_color;
	char *str_intensity;

	lst_light_append(&(data->light), light);
	strs_point = ft_split_any(strs[1], ',');
	if (!strs_point)
		serialize_error(ERROR_ERRNO, errno, data, strs);
	set_point(data, strs, strs_point, &light);
}

t_data  *serialize_l(t_data *data, char const *line, char **strs)
{
	size_t	strslen;
	t_light	*light;

	line += ft_strlen(LABEL_LIGHT);
	if (!ft_isspace(*line))
		serialize_error(ERROR_SYNTAX_LIGHT, 255, data, strs);
	strslen = ft_strslen(strs);
	if (strslen != 4)
		serialize_error(ERROR_SYNTAX_LIGHT, 255, data, strs);
	light = NULL;
	if (!(alloca_to((void**)&light, sizeof(t_light))))
		serialize_error(ERROR_ERRNO, errno, data, strs);
	light->next = NULL;
	set_light(data, strs, light);
	return (data);
}

