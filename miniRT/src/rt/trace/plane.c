/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 23:38:34 by rmander           #+#    #+#             */
/*   Updated: 2021/05/08 23:40:42 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static t_pair_double_int	_trace_plane(t_data *data, t_vector3 *dirvec, t_pair_double *steprange)
{
	t_pair_double_int	pair;
	double				step;

	pair.first = INFINITY;
	pair.second = FALSE;
	step = intersect_plane(data, dirvec, data->figures->plane);
	if (step >= steprange->first && step <= steprange->second && step < pair.first)
	{
		pair.first = step;
		pair.second = TRUE;
	}
	return (pair);
}

int	_t_plane(t_data *data, t_vector3 *dirvec, t_pair_double *steprange)
{
	t_vector3			closest_point;
	t_vector3			t_mult_dirvec;
	int					color;
	t_pair_double_int	pair;

	color = data->figures->plane->color;
	pair = _trace_plane(data, dirvec, steprange);
	if (!pair.second)
		return (COLOR_BACKGROUND);
	t_mult_dirvec = cmultvec3(pair.first, dirvec);
	closest_point = sumvec3(&data->cam->center, &t_mult_dirvec);
	color = light(data, &closest_point, &data->figures->plane->orient, color);
	return (color);
}
