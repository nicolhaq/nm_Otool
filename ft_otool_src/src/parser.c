/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:49:10 by nhaquet           #+#    #+#             */
/*   Updated: 2018/10/16 20:24:55 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_otool.h"

void	ft_parse(char **argv, int argc)
{
	int	i;

	i = 0;
	if (argc == 1)
		argv[0] = "a.out\0";
	else
	{
		while (argv[i] != NULL)
		{
			argv[i] = argv[i + 1];
			i++;
		}
	}
}
