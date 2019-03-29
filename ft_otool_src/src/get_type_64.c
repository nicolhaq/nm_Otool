/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type_64.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 14:52:38 by nhaquet           #+#    #+#             */
/*   Updated: 2018/11/06 15:22:48 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_otool.h"

void	print_hexdump_64(struct section_64 *sect, char *ptr)
{
	int		j;
	size_t	offset;

	offset = 0;
	while (endian_4(sect->offset) + offset != endian_4(sect->offset)
		+ endian_8(sect->size))
	{
		j = 0;
		ptr_to_hex(endian_8(sect->addr) + offset, TRUE);
		ft_putchar('\t');
		while (j++ != 16)
		{
			byte_to_hex(*(ptr + sect->offset + offset));
			offset++;
			ft_putchar(' ');
			if (endian_4(sect->offset) + offset == endian_4(sect->offset)
				+ endian_8(sect->size))
				break ;
		}
		ft_putchar('\n');
	}
}

int		sec_symb_64(struct segment_command_64	*seg, char *ptr, void *endptr)
{
	struct section_64	*sect;

	sect = (struct section_64 *)((char *)seg
		+ sizeof(struct segment_command_64));
	if ((void*)sect + sizeof(struct section_64) > endptr)
		return (-2);
	if ((!ft_strcmp(sect->segname, "__TEXT"))
		&& (!ft_strcmp(sect->sectname, "__text")))
	{
		ft_putstr("Contents of (__TEXT,__text) section\n");
		print_hexdump_64(sect, ptr);
	}
	return (0);
}

int		get_seg_type_64(char *ptr, void *endptr)
{
	struct mach_header_64		*header;
	struct load_command			*lc;
	struct segment_command_64	*seg;
	unsigned int				i;

	i = 0;
	header = (struct mach_header_64 *)ptr;
	lc = (void *)ptr + sizeof(*header);
	while (i < endian_4(header->ncmds))
	{
		if (lc->cmd == LC_SEGMENT_64)
		{
			seg = (struct segment_command_64 *)lc;
			if (((void*)seg + sizeof(struct segment_command_64) > endptr)
				|| (sec_symb_64(seg, ptr, endptr) != 0))
				return (-2);
		}
		lc = (struct load_command *)(((char *)lc) + endian_4(lc->cmdsize));
		if ((void *)lc > endptr)
			return (-2);
		i++;
	}
	return (0);
}
