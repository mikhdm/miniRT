/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:28:45 by rmander           #+#    #+#             */
/*   Updated: 2021/05/23 20:22:29 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "libft.h"
#include "parsing/serialize.h"

static t_data *serialize_figure(t_data *data, char const *line)
{
	size_t i;
	size_t size;
	const char *label[] = {LABEL_SPHERE, LABEL_CYLINDER,
	                       LABEL_PLANE, LABEL_TRIANGLE, LABEL_SQUARE};
	const t_serialize_func func[] = {&serialize_sp, &serialize_cy,
	                                 &serialize_pl, &serialize_tr,
	                                 &serialize_sq};

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

static t_data   *serialize_scene(t_data *data, char const *line)
{

	size_t  i;
	size_t  size;
	const char *label[] = {LABEL_RESOLUTION, LABEL_AMBIENCE, LABEL_CAMERA,
							LABEL_LIGHT};
	const t_serialize_func func[] = {&serialize_R, &serialize_A, &serialize_c,
								    &serialize_l};

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

t_data  *serialize(t_data *data, char *line)
{
	data = serialize_scene(data, line);
	data = serialize_figure(data, line);
	return (data);
}