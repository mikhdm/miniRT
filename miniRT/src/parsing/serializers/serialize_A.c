/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize_A.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 03:58:59 by rmander           #+#    #+#             */
/*   Updated: 2021/05/28 20:11:29 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "libft.h"
#include "parsing/errors.h"
#include "parsing/serialize.h"
#include <errno.h>

t_data  *serialize_A(t_data *data, char const *line)
{
	char	**strs;
	char 	*str;
	size_t 	strslen;
	size_t 	i;

	strs = NULL;
	str = NULL;
	line += ft_strlen(LABEL_AMBIENCE);
	if (!ft_isspace(*line))
		serialize_exitfree(ERROR_SYNTAX_AMBIENCE, 255, data, NULL);
	strs = ft_splitf(line, &ft_isspace);
	if (!strs)
		serialize_exitfree(ERROR_ERRNO, errno, data, NULL);
	strslen = ft_strslen(strs);
	if (strslen != 2)
		serialize_exitfree(ERROR_SYNTAX_AMBIENCE, 255, data, strs);
	i = 0;
	while (i < strslen)
	{
		str = strs[i++];
	}
	return (data);
}
