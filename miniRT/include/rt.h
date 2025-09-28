/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:48:55 by rmander           #+#    #+#             */
/*   Updated: 2021/04/14 00:17:08 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

typedef	struct	s_meta
{
	void		*mlx;
	void		*window;
	void		*img;
    char		*addr;
    int			bpp;
    int         length;
    int         endian;
}               t_meta;

void	ft_defaults_meta(t_meta *meta);
void	ft_putpixel(void **img, int x, int y, int color);


#endif
