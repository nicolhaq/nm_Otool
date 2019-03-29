/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:20:50 by nhaquet           #+#    #+#             */
/*   Updated: 2018/10/18 16:03:58 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_nm.h"

void	swap(t_data *a, t_data *b)
{
	t_data tmp;

	if (a == b)
		return ;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort_array(t_data **darray, int begin, int end)
{
	int		pivot;
	int		i;
	int		j;

	if (begin < end)
	{
		pivot = begin;
		i = begin;
		j = end;
		while (i < j)
		{
			while ((ft_strcmp(darray[i]->name, darray[pivot]->name) <= 0)
					&& i < end)
				i++;
			while (ft_strcmp(darray[j]->name, darray[pivot]->name) > 0)
				j--;
			if (i < j)
				swap(darray[i], darray[j]);
		}
		swap(darray[pivot], darray[j]);
		sort_array(darray, begin, j - 1);
		sort_array(darray, j + 1, end);
	}
}
