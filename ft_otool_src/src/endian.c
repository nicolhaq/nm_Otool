/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endian.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 15:02:07 by nhaquet           #+#    #+#             */
/*   Updated: 2018/10/16 20:48:29 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_otool.h"
#include <stdbool.h>

static bool			g_little_endian = false;

void				endian_little_mode(bool is_little_endian)
{
	g_little_endian = is_little_endian;
}

uint16_t			endian_2(uint16_t n)
{
	if (g_little_endian)
		return ((n >> 8) | (n << 8));
	return (n);
}

uint32_t			endian_4(uint32_t n)
{
	if (g_little_endian)
	{
		return ((n >> 24) | ((n & 0xff0000) >> 8) | \
		((n & 0xff00) << 8) | (n << 24));
	}
	return (n);
}

uint64_t			endian_8(uint64_t n)
{
	if (g_little_endian)
	{
		return ((n & 0xff00000000000000) >> 56 \
		| (n & 0x00ff000000000000) >> 40 \
		| (n & 0x0000ff0000000000) >> 24 \
		| (n & 0x000000ff00000000) >> 8 \
		| (n & 0x00000000ff000000) << 8 \
		| (n & 0x0000000000ff0000) << 24 \
		| (n & 0x000000000000ff00) << 40 \
		| (n & 0x00000000000000ff) << 56);
	}
	return (n);
}
