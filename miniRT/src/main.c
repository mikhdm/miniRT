/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:37:11 by rmander           #+#    #+#             */
/*   Updated: 2021/04/10 23:32:23 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	t_meta	meta;
	void	*mlx;
	void	*window;
	
	meta = (t_meta) {.img = NULL, .addr = NULL, .bpp = 0, .length = 0, .endian = 0};
	printf("%s\n", meta.img);

	mlx = mlx_init();
	window = mlx_new_window(mlx, 800, 600, "miniRT");
	mlx_loop(window);
	return (0);
}
