/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:29:05 by rmander           #+#    #+#             */
/*   Updated: 2021/05/28 18:12:08 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_H
# define SERIALIZE_H

#include "canvas.h"

typedef t_data *(*t_serialize_func)(t_data *, char const *);

t_data  *serialize(t_data *data, char *line);
void	serialize_exitfree(int code, int status, t_data *data, char **strs);

t_data  *serialize_R(t_data *data, char const *line);
t_data  *serialize_A(t_data *data, char const *line);
t_data  *serialize_c(t_data *data, char const *line);
t_data  *serialize_l(t_data *data, char const *line);
t_data  *serialize_sp(t_data *data, char const *line);
t_data  *serialize_cy(t_data *data, char const *line);
t_data  *serialize_pl(t_data *data, char const *line);
t_data  *serialize_tr(t_data *data, char const *line);
t_data  *serialize_sq(t_data *data, char const *line);

#endif