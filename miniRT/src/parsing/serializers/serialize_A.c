/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize_A.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 03:58:59 by rmander           #+#    #+#             */
/*   Updated: 2021/05/28 23:34:09 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "libft.h"
#include "utils.h"
#include "parsing/errors.h"
#include "parsing/serialize.h"
#include "parsing/validate.h"
#include <errno.h>

static void set_ambience(t_data *data, char **strs)
{
	size_t		strslen;
	t_ambience	*ambience;
	char 		**strs_rgb;
	int			argb;

	ambience = NULL;
	strs_rgb = NULL;
	argb = COLOR_BACKGROUND;
	strslen = ft_strslen(strs);
	if (strslen != 2)
		serialize_error(ERROR_SYNTAX_AMBIENCE, 255, data, strs);
	if (!alloca_to((void**)&ambience, sizeof(t_ambience)))
		serialize_error(ERROR_ERRNO, errno, data, strs);
	if (!ft_isfloatable(strs[0]))
		serialize_error(ERROR_SYNTAX_AMBIENCE, 255, data, strs);
	ambience->intensity = ft_atof(strs[0]);

	/* TODO fix split */
	strs_rgb = ft_split(strs[1], ',');

	if (!strs_rgb)
		serialize_error(ERROR_ERRNO, errno, data, strs);
	if (ft_strslen(strs_rgb) != 3)
		serialize_error(ERROR_SYNTAX_AMBIENCE, 255, data, strs);
	if (!valid_rgb((const char **)strs_rgb, strslen, &argb))
		serialize_error(ERROR_INVALID_AMBIENCE, 255, data, strs);
	ambience->color = argb;
	data->ambience = ambience;
}

t_data  *serialize_A(t_data *data, char const *line)
{
	char	**strs;

	line += ft_strlen(LABEL_AMBIENCE);
	if (!ft_isspace(*line))
		serialize_error(ERROR_SYNTAX_AMBIENCE, 255, data, NULL);
	strs = ft_splitf(line, &ft_isspace);
	if (!strs)
		serialize_error(ERROR_ERRNO, errno, data, NULL);
	set_ambience(data, strs);
	return (data);
}
