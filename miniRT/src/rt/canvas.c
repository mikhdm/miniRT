/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 02:29:22 by rmander           #+#    #+#             */
/*   Updated: 2021/06/07 13:21:36 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "linop.h"
#include "utils.h"
#include "libft.h"
#include "MLX42/MLX42.h"
#include "MLX42/MLX42_Int.h"
#include <stdlib.h>
#include <errno.h>
#include <math.h>

static t_vector3	get_dirvec(t_vector3 *viewpoint)
{
    t_vector3	basis[3];
    t_vector3	xu;
    t_vector3	yv;
    t_vector3	dw;
    t_vector3	dirvec;

    basis[0] = (t_vector3){1, 0, 0};
    basis[1] = (t_vector3){0, 1, 0};
    basis[2] = (t_vector3){0, 0, -1};
    xu = cmultvec3(viewpoint->x, &basis[0]);
    yv = cmultvec3(viewpoint->y, &basis[1]);
    dw = cmultvec3(viewpoint->z, &basis[2]);
    dirvec = sumvec3(&xu, &yv);
    dirvec = sumvec3(&dirvec, &dw);
    return (dirvec);
}

t_viewport	calc_viewport(t_data *data, t_camera *cam)
{
    t_viewport	viewport;
    double		fov;

    fov = cam->fov;
    if (ft_fequal(cam->fov, 180))
        fov -= 1e-2;
    viewport.width = 2 * tan(deg_to_rad(fov / 2));
    viewport.height = data->screen->height
        * (viewport.width / (double)data->screen->width);
    return (viewport);
}

/*
*
* canvas_to_viewport - camera position independent ray direction calc.
*
*/
t_vector3	canvas_to_viewport(t_data *data, t_camera *cam, int x, int y)
{
    t_vector3	dirvec;
    t_vector3	viewpoint;

    viewpoint.x = (cam->viewport->width / (double)data->screen->width)
        * (x + 0.5);
    viewpoint.y = (cam->viewport->height / (double)data->screen->height)
        * (y + 0.5);
    viewpoint.z = -1;
    dirvec = get_dirvec(&viewpoint);
    return (normvec3(&dirvec));
}

void	init(t_data *data, short headless)
{
    if (headless)
        mlx_set_setting(MLX_HEADLESS, true);
    data->mlx = mlx_init(
        data->screen->width,
        data->screen->height,
        data->screen->title,
        true);
    data->bpp = BPP;
    data->img = mlx_new_image(
            data->mlx,
            data->screen->width,
            data->screen->height);
}
