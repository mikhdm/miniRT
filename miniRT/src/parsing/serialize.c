/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:28:45 by rmander           #+#    #+#             */
/*   Updated: 2021/06/04 03:20:49 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "libft.h"
#include "parsing/errors.h"
#include "parsing/serialize.h"
#include <errno.h>

short	one_of(char *value, char const **strs)
{
	while (*strs)
	{
		if (ft_strcmp(value, *strs++) == 0)
			return (TRUE);
	}
	return (FALSE);
}

static t_data	*loop(t_data *data, char *line,
					const char **label, const t_serialize_func func[])
{
	short 	set;
	char	**strs;

	strs = NULL;
	set = FALSE;
	while (*label && !set)
	{
		if (*line)
			strs = ft_splitf(line, &ft_isspace);
		if (!strs)
			ft_pexitfree(ERROR_ERRNO, errno, data);
		if (ft_strcmp(strs[0], *label) == 0)
		{
			data = (*func)(data, line, strs);
			set = TRUE;
		}
		if (!one_of(strs[0], label))
			serialize_error(ERROR_SYNTAX, 255, data, strs);
		ft_strsfree(strs);
		strs = NULL;
		++label;
		++func;
	}
	return (data);
}

t_data  *serialize(t_data *data, char *line)
{
	const char *label[] = {LABEL_RESOLUTION, LABEL_AMBIENCE, LABEL_CAMERA,
						   LABEL_LIGHT, LABEL_SPHERE, LABEL_CYLINDER,
						   LABEL_PLANE, LABEL_TRIANGLE, LABEL_SQUARE, NULL};
	const t_serialize_func func[] = {&serialize_r, &serialize_a, &serialize_c,
								  &serialize_l, &serialize_sp, &serialize_cy,
								  &serialize_pl, &serialize_tr, &serialize_sq,
								  NULL};

	data = loop(data, line, label, func);
	return (data);
}

void serialize_error(int code, int status, t_data *data, char **strs)
{
	if (strs)
		ft_strsfree(strs);
	if (data)
		ft_pexitfree(code, status, data);
	ft_pexit(code, status);

}