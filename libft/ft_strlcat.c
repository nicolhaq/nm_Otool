/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:47:00 by nhaquet           #+#    #+#             */
/*   Updated: 2018/05/11 11:45:51 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char		*desti;
	const char	*source;
	size_t		buf;
	size_t		destlen;

	desti = dest;
	source = src;
	buf = size;
	while (buf-- != 0 && *desti != '\0')
		desti++;
	destlen = desti - dest;
	buf = size - destlen;
	if (buf == 0)
		return (destlen + ft_strlen(source));
	while (*source != '\0')
	{
		if (buf != 1)
		{
			*desti++ = *source;
			buf--;
		}
		source++;
	}
	*desti = '\0';
	return (destlen + (source - src));
}
