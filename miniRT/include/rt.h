/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:48:55 by rmander           #+#    #+#             */
/*   Updated: 2021/04/12 21:49:40 by rmander          ###   ########.fr       */
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

void	ft_putpixel(void **img, int x, int y, int color);

int		ft_hook_close(int keycode, t_meta *meta);

#endif
