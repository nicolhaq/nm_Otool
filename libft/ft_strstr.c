/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 10:14:16 by nhaquet           #+#    #+#             */
/*   Updated: 2018/05/11 11:46:52 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL)
		return (NULL);
	if (s2 == NULL)
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i] == s2[j] && ((s1[i] != '\0') || (s2[j] != '\0')))
		{
			i++;
			j++;
		}
		if (s2[j] == '\0')
			return ((char *)s1 + i - j);
		i = i - j + 1;
	}
	return (NULL);
}
