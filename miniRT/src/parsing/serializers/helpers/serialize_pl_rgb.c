/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize_pl_rgb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 16:04:31 by rmander           #+#    #+#             */
/*   Updated: 2021/06/02 16:05:33 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "libft.h"
#include "parsing/serialize.h"
#include "parsing/errors.h"
#include <stddef.h>

void	serialize_pl_rgb(t_data *data, char **strs, char **strs_rgb,
						 t_plane **plane)
{
	int		rgba;

	rgba = COLOR_BACKGROUND;
	if (!serialize_rgb(strs_rgb, &rgba))
	{
		ft_strsfree(strs_rgb);
		serialize_error(ERROR_INVALID_PLANE, 255, data, strs);
	}
	(*plane)->color = rgba;
	ft_strsfree(strs_rgb);
	strs_rgb = NULL;
}
