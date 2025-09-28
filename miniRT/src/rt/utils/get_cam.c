/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:45:37 by rmander           #+#    #+#             */
/*   Updated: 2021/06/03 16:16:16 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "utils.h"
#include <stddef.h>

t_camera	*get_cam(t_data *data, short position)
{
	t_camera	*cam;
	t_camera	*prev;

	if (!data->cam)
		return (NULL);
	cam = data->cam;
	prev = data->cam;
	while (cam)
	{
		if (cam->active)
			break ;
		prev = cam;
		cam = cam->next;
	}
	if (!cam)
		return (data->cam);
	cam->active = FALSE;
	if (position == POS_CAM_NEXT)
	{
		cam = cam->next;
		if (!cam)
			cam = data->cam;
	}
	if (position == POS_CAM_PREV)
		cam = prev;
		// TODO go back correctly if cam == data->cam
	cam->active = TRUE;
	return (cam);
}