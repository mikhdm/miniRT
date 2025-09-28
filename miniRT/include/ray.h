/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:24:38 by rmander           #+#    #+#             */
/*   Updated: 2021/04/18 20:27:23 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

void ft_intersect_ray(t_meta *meta, t_vector3 *distvec, t_figure *figures);
void ft_trace_ray(t_meta *meta, t_vector3 *distvec, t_figure *figures, double tmin, double tmax);

#endif
