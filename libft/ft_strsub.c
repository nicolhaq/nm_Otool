/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 17:49:26 by nhaquet           #+#    #+#             */
/*   Updated: 2018/05/11 11:38:20 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_str;

	if (s != NULL)
	{
		new_str = ft_strnew(len);
		ft_strncpy(new_str, (char *)&s[start], len);
		return (new_str);
	}
	else
	{
		return (NULL);
	}
}
