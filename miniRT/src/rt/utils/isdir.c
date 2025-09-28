/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 21:56:22 by rmander           #+#    #+#             */
/*   Updated: 2021/06/07 04:29:46 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

short	isdir(int fildes)
{
	char	buff[1];
	ssize_t	rval;

	rval = read(fildes, buff, 0);
	if (rval == -1)
	{
		close(fildes);
		return (TRUE);
	}
	return (FALSE);
}
