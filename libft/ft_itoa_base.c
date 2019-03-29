/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:47:12 by nhaquet           #+#    #+#             */
/*   Updated: 2018/09/20 15:46:06 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isnegative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char		*ft_itoa_base(int n, unsigned int base)
{
	int		tmpn;
	int		len;
	int		negative;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmpn = n;
	len = 2;
	negative = ft_isnegative(n);
	while (tmpn /= base)
		len++;
	len += negative;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = ((n % base + '0') > '9')
			? ((n % base + '0') + 39) : (n % base + '0');
		n = n / base;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
