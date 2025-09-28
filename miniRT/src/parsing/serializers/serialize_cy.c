/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize_cy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 04:00:25 by rmander           #+#    #+#             */
/*   Updated: 2021/06/01 15:23:37 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "utils.h"
#include "libft.h"
#include "parsing/errors.h"
#include "parsing/serialize.h"
#include <errno.h>

static void	set_color(t_data *data, char **strs, char **strs_rgb,
						 t_cylinder **cylinder)
{
	int		argb;

	argb = COLOR_BACKGROUND;
	if (!serialize_rgb(strs_rgb, &argb))
	{
		ft_strsfree(strs_rgb);
		serialize_error(ERROR_INVALID_CYLINDER, 255, data, strs);
	}
	(*cylinder)->color = argb;
	ft_strsfree(strs_rgb);
	strs_rgb = NULL;
}

static void	set_orient(t_data *data, char **strs, char **strs_orient,
						 t_cylinder **cylinder)
{
	if (!serialize_orient(strs_orient, &(*cylinder)->orient))
	{
		ft_strsfree(strs_orient);
		serialize_error(ERROR_INVALID_CYLINDER, 255, data, strs);
	}
	ft_strsfree(strs_orient);
	strs_orient = NULL;
}

static void	set_point(t_data *data, char **strs, char **strs_point,
						 t_cylinder **cylinder)
{
	if (!serialize_point(strs_point, &(*cylinder)->center))
	{
		ft_strsfree(strs_point);
		serialize_error(ERROR_INVALID_CYLINDER, 255, data, strs);
	}
	ft_strsfree(strs_point);
	strs_point = NULL;
}

static void	set_figure(t_data *data, char **strs, t_cylinder **cylinder)
{
	t_figure	*figure;

	figure = NULL;
	if (!(alloca_to((void **)&figure, sizeof(t_figure))))
	{
		free(*cylinder);
		serialize_error(ERROR_ERRNO, errno, data, strs);
	}
	figure->label = LABEL_SPHERE;
	figure->next = NULL;
	figure->content = *cylinder;
	lst_figure_append(&data->figures, figure);
}

static void set_cylinder(t_data *data, char **strs, t_cylinder *cylinder)
{
	char **strs_point;
	char **strs_orient;
	char **strs_rgb;

	set_figure(data, strs, &cylinder);
	strs_point = ft_split_any(strs[1], ',');
	if (!strs_point)
		serialize_error(ERROR_ERRNO, errno, data, strs);
	set_point(data, strs, strs_point, &cylinder);
	strs_orient = ft_split_any(strs[2], ',');
	if (!strs_orient)
		serialize_error(ERROR_ERRNO, errno, data, strs);
	set_orient(data, strs, strs_orient, &cylinder);
	if (!ft_isfloatable(strs[3]) || !ft_isfloatable(strs[4]))
		serialize_error(ERROR_SYNTAX_CYLINDER, 255, data, strs);
	cylinder->diameter = ft_atof(strs[3]);
	cylinder->height = ft_atof(strs[4]);
	if (ft_flt(cylinder->diameter, 0) || ft_flt(cylinder->height, 0))
		serialize_error(ERROR_INVALID_CYLINDER, 255, data, strs);
	strs_rgb = ft_split_any(strs[5], ',');
	if (!strs_rgb)
		serialize_error(ERROR_ERRNO, errno, data, strs);
	set_color(data, strs, strs_rgb, &cylinder);
}

t_data  *serialize_cy(t_data *data, char const *line, char **strs)
{
	size_t		strslen;
	t_cylinder	*cylinder;

	line += ft_strlen(LABEL_CYLINDER);
	if (!ft_isspace(*line))
		serialize_error(ERROR_SYNTAX_CYLINDER, 255, data, strs);
	strslen = ft_strslen(strs);
	if (strslen != 6)
		serialize_error(ERROR_SYNTAX_CYLINDER, 255, data, strs);
	cylinder = NULL;
	if (!(alloca_to((void **)&cylinder, sizeof(t_cylinder))))
		serialize_error(ERROR_ERRNO, 255, data, strs);
	set_cylinder(data, strs, cylinder);
	return (data);
}
