/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:28:45 by rmander           #+#    #+#             */
/*   Updated: 2021/05/31 05:00:20 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "libft.h"
#include "parsing/errors.h"
#include "parsing/serialize.h"
#include <errno.h>

t_data  *serialize(t_data *data, char *line)
{
	size_t  i;
	const char *label[] = {LABEL_RESOLUTION, LABEL_AMBIENCE, LABEL_CAMERA,
						   LABEL_LIGHT, LABEL_SPHERE, LABEL_CYLINDER,
						   LABEL_PLANE, LABEL_TRIANGLE, LABEL_SQUARE};
	const t_serialize_func func[] = {&serialize_r, &serialize_a, &serialize_c,
								  &serialize_l, &serialize_sp, &serialize_cy,
								  &serialize_pl, &serialize_tr, &serialize_sq};
	char	**strs;

	i = 0;
	strs = NULL;
	while (i < (sizeof(label) / sizeof(*label)))
	{
		if (*line)
			strs = ft_splitf(line, &ft_isspace);
		if (!strs)
			ft_pexitfree(ERROR_ERRNO, errno, data);
		if (ft_strcmp(strs[0], label[i]) == 0)
			data = (*func[i])(data, line, strs);
		ft_strsfree(strs);
		strs = NULL;
		++i;
	}
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