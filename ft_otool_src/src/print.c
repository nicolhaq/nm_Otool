/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 17:48:44 by nhaquet           #+#    #+#             */
/*   Updated: 2018/11/06 13:37:14 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_otool.h"

void	byte_to_hex(char byte)
{
	char			str[3];
	unsigned short	i;
	short			hex;
	unsigned char	cast;

	cast = (unsigned char)byte;
	i = 0;
	while (i != 2)
	{
		hex = cast % 16;
		cast /= 16;
		if (hex < 10)
			str[i] = hex + '0';
		else
			str[i] = (hex % 10) + 'a';
		i++;
	}
	ft_putchar(str[1]);
	ft_putchar(str[0]);
}

void	ptr_to_hex(size_t ptr, boolean_t len64)
{
	char	str[16];
	short	count;
	short	char_hex;

	count = -1;
	while (++count != 16)
	{
		char_hex = ptr % 16;
		ptr /= 16;
		if (char_hex < 10)
			str[count] = char_hex + '0';
		else
			str[count] = (char_hex % 10) + 'a';
	}
	count--;
	if (!len64)
		count -= 8;
	while (count >= 0)
		ft_putchar(str[count--]);
}

int		print_output(t_file *fdata, int is_64, void *endptr)
{
	if (is_64)
	{
		return (get_seg_type_64(fdata->ptr, endptr));
	}
	else
	{
		return (get_seg_type(fdata->ptr, endptr));
	}
}

void	print_file(int argc, char **argv, int i)
{
	if (argc >= 2)
	{
		ft_putstr(argv[i]);
		ft_putstr(":\n");
	}
}
