/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 11:56:41 by nhaquet           #+#    #+#             */
/*   Updated: 2014/01/06 12:12:40 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_sqrt(double num)
{
	int		max;
	double	error;
	double	ans;
	double	sqr;
	int		step;

	max = 40;
	error = 0.001;
	ans = num;
	sqr = ans * ans;
	step = 0;
	if (num < 0)
	{
		ft_putstr("error:the number is negatif");
		return (-1);
	}
	while ((sqr - num > error) && (step++ < max))
	{
		ans = (ans + (num / ans)) / 2;
		sqr = ans * ans;
	}
	return (ans);
}
