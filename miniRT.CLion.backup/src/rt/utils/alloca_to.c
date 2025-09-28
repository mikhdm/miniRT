/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloca_to.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 22:12:14 by rmander           #+#    #+#             */
/*   Updated: 2021/05/14 22:27:16 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

short int   alloca_to(void** ptr, size_t size)
{
	*ptr = malloc(size);
	if (!*ptr)
		return (FALSE);
	return (TRUE);
}