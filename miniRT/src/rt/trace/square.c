/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 23:37:35 by rmander           #+#    #+#             */
/*   Updated: 2021/05/12 22:31:57 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "intersect.h"
#include "linop.h"
#include "light.h"
#include "utils.h"

static double	_trace(t_data *data,
					t_vector3 *dirvec, t_pair_double *range)
{
	double	step;
	double	closest_step;

	step = intersect_square(data, dirvec, data->figures->square);
	closest_step = INFINITY;
	if (step >= range->first && step <= range->second &&
		step < closest_step)
		closest_step = step; 
	return (closest_step);
}

int	trace_square(t_data *data,
		t_vector3 *dirvec, t_pair_double *range)
{
	t_vector3			closest_point;
	t_vector3			t_mult_dirvec;
	double				step;
	int					color;
	t_vector3			orient;

	color = data->figures->square->color;
	orient = data->figures->square->orient; 
	step = _trace(data, dirvec, range);
	if (isinf(step))
		return (COLOR_BACKGROUND);
	t_mult_dirvec = cmultvec3(step, dirvec);
	closest_point = sumvec3(&data->cam->center, &t_mult_dirvec);
	
	t_vector3	rand_vec;
	t_vector3	sq_vec[4];
	t_vector3	vertices[4];
	size_t		i;

	rand_vec = (t_vector3) {.x = 1000, .y = 0, .z = 0};
	if (iscollinvec3(&rand_vec, &orient)) 
		rand_vec = (t_vector3) {.x = 0, .y = 1000, .z = 0};

	sq_vec[0] = cross3(&rand_vec, &orient);
	sq_vec[1] = cross3(&sq_vec[0], &orient);

	sq_vec[0] = normvec3(&sq_vec[0]);
	sq_vec[1] = normvec3(&sq_vec[1]);
	sq_vec[2] = cmultvec3(-1.0, &sq_vec[0]);
	sq_vec[3] = cmultvec3(-1.0, &sq_vec[1]);

	i = 0;
	while (i < 4)
	{
		sq_vec[i] = cmultvec3(data->figures->square->size * pow (2, -0.5),
						&sq_vec[i]);
		vertices[i] = sumvec3(&sq_vec[i], &data->figures->square->center);
		++i;
	}

	t_vector3	phit_p1_vec = diffvec3(&vertices[0], &closest_point);
	t_vector3	phit_p2_vec = diffvec3(&vertices[1], &closest_point);
	t_vector3	phit_p3_vec = diffvec3(&vertices[2], &closest_point);
	t_vector3	phit_p4_vec = diffvec3(&vertices[3], &closest_point);

	t_vector3	cross1vec = cross3(&phit_p1_vec, &phit_p2_vec);
	t_vector3	cross2vec = cross3(&phit_p2_vec, &phit_p3_vec);
	t_vector3	cross3vec = cross3(&phit_p3_vec, &phit_p4_vec);
	t_vector3	cross4vec = cross3(&phit_p4_vec, &phit_p1_vec);

	double	check1 = dot3(&cross1vec, &orient); 
	double	check2 = dot3(&cross2vec, &orient); 
	double	check3 = dot3(&cross3vec, &orient); 
	double	check4 = dot3(&cross4vec, &orient); 

	if ((check1 > 0 && check2 > 0 && check3 > 0 && check4 > 0) ||
		(check1 < 0 && check2 < 0 && check3 < 0 && check4 < 0))
	{
		color = light(data, &closest_point, &orient, color);
		return (color);
	}
	return (COLOR_BACKGROUND);
}
