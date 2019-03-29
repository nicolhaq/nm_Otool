/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 19:19:09 by nhaquet           #+#    #+#             */
/*   Updated: 2018/05/11 11:46:46 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_gety(const char *s, const char sep)
{
	size_t	y;
	size_t	i;

	y = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == sep && s[i] != '\0')
		{
			i++;
		}
		if (s[i] != sep && s[i] != '\0')
			y++;
		while (s[i] != sep && s[i] != '\0')
		{
			i++;
		}
	}
	return (y);
}

static char		**ft_strnew2d(size_t len)
{
	char	**new_str;

	if ((new_str = (char **)malloc(sizeof(char *) * len + 1)) == NULL)
		return (NULL);
	ft_bzero(new_str, len);
	return (new_str);
}

static size_t	ft_strpos(const char *s, const char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char			**ft_strsplit(const char *s, const char c)
{
	char	**dest;
	size_t	y;
	size_t	x;
	size_t	pos;
	size_t	i;

	i = 0;
	y = ft_gety(s, c);
	if ((dest = ft_strnew2d(y)) == NULL)
		return (NULL);
	dest[y] = NULL;
	x = 0;
	while (i < y)
	{
		while (s[x] == c)
			x++;
		pos = ft_strpos(&s[x], c);
		dest[i] = ft_strsub(s, x, pos);
		x += pos;
		i++;
	}
	return (dest);
}
