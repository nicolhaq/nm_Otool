/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 19:22:03 by nhaquet           #+#    #+#             */
/*   Updated: 2018/05/11 11:41:46 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup2(const char *s1)
{
	int		len;
	int		index;
	char	*dup;

	len = ft_strlen(s1);
	index = 0;
	dup = malloc((len + 1) * sizeof(*dup));
	if (dup == NULL)
	{
		return (NULL);
	}
	while (s1[index] != '\0')
	{
		dup[index] = s1[index];
		index++;
	}
	dup[index] = '\0';
	return (dup);
}
