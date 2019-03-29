/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:53:34 by nhaquet           #+#    #+#             */
/*   Updated: 2018/05/11 11:44:15 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	temp1;
	unsigned char	temp2;

	while (n--)
	{
		temp1 = *(unsigned char *)s1++;
		temp2 = *(unsigned char *)s2++;
		if (temp1 != temp2)
			return (temp1 - temp2);
	}
	return (0);
}
