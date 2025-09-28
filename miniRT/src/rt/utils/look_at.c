/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_at.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 07:09:35 by rmander           #+#    #+#             */
/*   Updated: 2021/06/04 07:21:54 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "linop.h"
#include "parsing/errors.h"
#include <stdlib.h>
#include <errno.h>

static double	**get_rot_matrix(t_data *data, t_vector3 *right, t_vector3 *up,
					t_camera *cam)
{
	double **rot;

	rot = malloc(sizeof(double*) * 3);
	if (!rot)
		ft_pexitfree(ERROR_ERRNO, errno, data);
	rot[0] = malloc(sizeof(double) * 3);
	rot[1] = malloc(sizeof(double) * 3);
	rot[2] = malloc(sizeof(double) * 3);
	if (!(rot[0] && rot[1] && rot[2]))
		ft_pexitfree(ERROR_ERRNO, errno, data);
	rot[0][0] = right->x;
	rot[1][0] = right->y;
	rot[2][0] = right->z;
	rot[0][1] = up->x;
	rot[1][1] = up->y;
	rot[2][1] = up->z;
	rot[0][2] = cam->orient.x;
	rot[1][2] = cam->orient.y;
	rot[2][2] = cam->orient.z;
	return (rot);
}

t_vector3	look_at(t_data *data, t_camera *cam, t_vector3 *dirvec)
{
	t_vector3	tmp;
	t_vector3	right;
	t_vector3	up;
	t_vector3	rot_dirvec;
	double		**rot;

	tmp = (t_vector3){.x = 0, .y = 100, .z = 0};
	if (!iscollinvec3(&tmp, &cam->orient))
	{
		right = cross3(&tmp, &cam->orient);
		up = cross3(&cam->orient, &right);
	}
	else
	{
		tmp = (t_vector3){.x = -100, .y = 0, .z = 0};
		up = cross3(&tmp, &cam->orient);
		right = cross3(&up, &cam->orient);
	}
	up = normvec3(&up);
	right = normvec3(&right);
	rot = get_rot_matrix(data, &right, &up, cam);
	rot_dirvec = mat33multvec3(rot, dirvec);
	free(rot[0]);
	free(rot[1]);
	free(rot[2]);
	free(rot);
	return (rot_dirvec);
}
