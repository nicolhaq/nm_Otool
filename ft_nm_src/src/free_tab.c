/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 11:38:47 by nhaquet           #+#    #+#             */
/*   Updated: 2018/09/20 15:50:15 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_nm.h"

void	free_tab(t_data **darray)
{
	int i;

	i = 0;
	while (darray[i] != NULL)
	{
		free(darray[i]->value);
		free(darray[i]);
		i++;
	}
	free(darray);
}
