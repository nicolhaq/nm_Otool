/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 14:52:38 by nhaquet           #+#    #+#             */
/*   Updated: 2018/11/06 15:21:46 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_otool.h"

void	print_hexdump(struct section *sect, char *ptr)
{
	int		j;
	size_t	offset;

	offset = 0;
	while (endian_4(sect->offset) + offset != endian_4(sect->offset)
		+ endian_4(sect->size))
	{
		j = 0;
		ptr_to_hex(endian_4(sect->addr) + offset, FALSE);
		ft_putchar('\t');
		while (j++ != 16)
		{
			byte_to_hex(*(ptr + endian_4(sect->offset) + offset));
			offset++;
			ft_putchar(' ');
			if (endian_4(sect->offset) + offset == endian_4(sect->offset)
				+ endian_4(sect->size))
				break ;
		}
		ft_putchar('\n');
	}
}

int		sec_symb(struct segment_command	*seg, char *ptr, void *endptr)
{
	struct section	*sect;

	sect = (struct section *)((char *)seg
		+ sizeof(struct segment_command));
	if ((void*)sect + sizeof(struct section_64) > endptr)
		return (-2);
	if ((!ft_strcmp(sect->segname, "__TEXT"))
		&& (!ft_strcmp(sect->sectname, "__text")))
	{
		ft_putstr("Contents of (__TEXT,__text) section\n");
		print_hexdump(sect, ptr);
	}
	return (0);
}

int		get_seg_type(char *ptr, void *endptr)
{
	struct mach_header			*header;
	struct load_command			*lc;
	struct segment_command		*seg;
	unsigned int				i;

	i = 0;
	header = (struct mach_header *)ptr;
	lc = (void *)ptr + sizeof(*header);
	while (i < endian_4(header->ncmds))
	{
		if (endian_4(lc->cmd) == LC_SEGMENT)
		{
			seg = (struct segment_command *)lc;
			if (((void*)seg + sizeof(struct segment_command) > endptr)
				|| (sec_symb(seg, ptr, endptr) != 0))
				return (-2);
		}
		lc = (struct load_command *)(((char *)lc) + endian_4(lc->cmdsize));
		i++;
	}
	return (0);
}
