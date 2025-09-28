/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize_cy_rgb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 20:00:52 by rmander           #+#    #+#             */
/*   Updated: 2021/06/01 20:16:26 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "libft.h"
#include "parsing/serialize.h"
#include "parsing/errors.h"
#include <stddef.h>

void	serialize_cy_rgb(t_data *data, char **strs, char **strs_rgb,
               t_cylinder **cylinder)
{
    int		rgba;

    rgba = COLOR_BACKGROUND;
    if (!serialize_rgb(strs_rgb, &rgba))
    {
        ft_strsfree(strs_rgb);
        serialize_error(ERROR_INVALID_CYLINDER, 255, data, strs);
    }
    (*cylinder)->color = rgba;
    ft_strsfree(strs_rgb);
    strs_rgb = NULL;
}
