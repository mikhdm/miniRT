/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 02:50:53 by rmander           #+#    #+#             */
/*   Updated: 2021/05/24 02:51:00 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

#include "canvas.h"

# define ERROR_HEADER   "ERROR\n"
# define ERROR_ERRNO    (-1)

typedef enum e_error
{
	ERROR_PATH_EMPTY = 0,
	ERROR_PATH_PARAM_EMPTY,
	ERROR_SCREENSHOT_PARAM_WRONG,
	ERROR_NUM_ARGS_WRONG,
	ERROR_SCENE_EXT_WRONG,
	ERROR_SYNTAX_RESOLUTION,
	ERROR_SYNTAX_AMBIENCE,
	ERROR_SYNTAX_CAMERA,
	ERROR_SYNTAX_LIGHT,
	ERROR_SYNTAX_SPHERE,
	ERROR_SYNTAX_CYLINDER,
	ERROR_SYNTAX_PLANE,
	ERROR_SYNTAX_TRIANGLE,
	ERROR_SYNTAX_SQUARE
}   t_error;

void    ft_perror(int code);
void    ft_pexit(int code, int status);
void    ft_pexitfree(int code, int status, t_data *data);

#endif