/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:50:15 by rmander           #+#    #+#             */
/*   Updated: 2021/04/14 00:12:48 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>

void	ft_defaults_meta(t_meta *meta) {
	meta->mlx = NULL;
	meta->window = NULL;
	meta->img = NULL;
	meta->addr = NULL;
	meta->bpp = 0;
	meta->length = 0;
	meta->endian = 0;
}
