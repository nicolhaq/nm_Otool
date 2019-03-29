/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 14:59:15 by nhaquet           #+#    #+#             */
/*   Updated: 2018/05/11 11:46:33 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s2 == NULL)
		return ((char *)s1);
	if (s1 == NULL)
		return (NULL);
	while (s1[i] != '\0' && n)
	{
		j = 0;
		while (s1[i] == s2[j] && ((s1[i] != '\0') || (s2[j] != '\0')) && n)
		{
			i++;
			j++;
			n--;
		}
		if (s2[j] == '\0')
			return ((char *)s1 + i - j);
		i = i - j + 1;
		n--;
	}
	return (NULL);
}
