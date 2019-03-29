/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:41:47 by nhaquet           #+#    #+#             */
/*   Updated: 2018/05/11 11:43:58 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	int		i;
	char	*temp1;
	char	*temp2;

	temp1 = s1;
	temp2 = (char *)s2;
	i = 0;
	while (n != 0)
	{
		if (temp2[i] == c)
		{
			temp1[i] = temp2[i];
			return (&temp1[i + 1]);
		}
		else
		{
			temp1[i] = temp2[i];
			i++;
			n--;
		}
	}
	return (NULL);
}
