/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 21:20:33 by rmander           #+#    #+#             */
/*   Updated: 2021/04/12 22:08:01 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "mlx.h"
#include "event.h"
#include <stdlib.h>
#include <stdio.h>

int ft_hook_close(int keycode, t_meta *meta)
{
	mlx_destroy_window(meta->mlx, meta->window);
	return (keycode);
}
