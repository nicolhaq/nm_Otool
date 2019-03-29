/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:56:26 by nhaquet           #+#    #+#             */
/*   Updated: 2018/05/11 11:44:44 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*temp1;
	unsigned char	*temp2;
	unsigned char	*buffer;

	temp1 = (unsigned char *)s1;
	temp2 = (unsigned char *)s2;
	buffer = (unsigned char *)malloc(sizeof(unsigned char) * (n + 1));
	ft_memcpy(buffer, temp2, n);
	ft_memcpy(temp1, buffer, n);
	return (temp1);
}
