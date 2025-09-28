/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 23:32:37 by rmander           #+#    #+#             */
/*   Updated: 2021/05/13 22:01:20 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_double(double *left, double *right)
{
	double tmp;

	tmp = *left;
	*left = *right;
	*right = tmp;
}
