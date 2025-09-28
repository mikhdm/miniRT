/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:07:57 by rmander           #+#    #+#             */
/*   Updated: 2021/05/28 21:49:01 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H

#include "canvas.h"
#include "linop.h"

t_data	*validate(t_data *data);

short	valid_rgb(const char **strs_rgb, size_t strslen, int *argb);
short	valid_orient(const char **strs_orient, size_t strslen,
			t_vector3 *orient);

#endif