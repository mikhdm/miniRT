/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:28:45 by rmander           #+#    #+#             */
/*   Updated: 2021/05/30 16:13:23 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "libft.h"
#include "parsing/errors.h"
#include "parsing/serialize.h"

t_data  *serialize(t_data *data, char *line)
{
	size_t  i;
	size_t  size;
	const char *label[] = {LABEL_RESOLUTION, LABEL_AMBIENCE, LABEL_CAMERA,
						   LABEL_LIGHT, LABEL_SPHERE, LABEL_CYLINDER,
						   LABEL_PLANE, LABEL_TRIANGLE, LABEL_SQUARE};
	const t_serialize_func func[] = {&serialize_r, &serialize_a, &serialize_c,
								  &serialize_l, &serialize_sp, &serialize_cy,
								  &serialize_pl, &serialize_tr, &serialize_sq};

	i = 0;
	size = sizeof(label) / sizeof(*label);
	while (i < size)
	{
		if (ft_strncmp(line, label[i], ft_strlen(label[i])) == 0)
			data = (*func[i])(data, line);
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