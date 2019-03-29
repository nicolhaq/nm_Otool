/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type_64.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 14:52:38 by nhaquet           #+#    #+#             */
/*   Updated: 2018/10/25 15:51:05 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_nm.h"

char	sec_symb_64(struct segment_command_64	*seg, int n)
{
	struct section_64		*sect;

	sect = (struct section_64 *)((char *)seg
		+ sizeof(struct segment_command_64));
	sect = sect + n;
	if (!ft_strcmp(sect->sectname, "__data"))
		return ('d');
	else if (!ft_strcmp(sect->sectname, "__bss"))
		return ('b');
	else if (!ft_strcmp(sect->sectname, "__text"))
		return ('t');
	return ('s');
}

char	get_seg_type_64(struct nlist_64 array, char *ptr)
{
	struct mach_header_64		*header;
	struct load_command			*lc;
	struct segment_command_64	*seg;
	unsigned int				i;
	int							n;

	i = 0;
	n = 0;
	header = (struct mach_header_64 *)ptr;
	lc = (void *)ptr + sizeof(*header);
	while (i < endian_4(header->ncmds))
	{
		if (endian_4(lc->cmd) == LC_SEGMENT_64)
		{
			seg = (struct segment_command_64 *)lc;
			if ((endian_4(seg->nsects) + n) >= endian_2(array.n_sect))
				return (sec_symb_64(seg, endian_2(array.n_sect) - n - 1));
			n = n + endian_4(seg->nsects);
		}
		lc = (struct load_command *)(((char *)lc) + endian_4(lc->cmdsize));
		i++;
	}
	return ('s');
}

char	is_ext_64(struct nlist_64 array, char c)
{
	if (((endian_2(array.n_type) & N_EXT) && (c != ' ')))
		c = ft_toupper(c);
	return (c);
}

char	get_type_64(struct nlist_64 array, char *ptr)
{
	if (((endian_2(array.n_type) & N_TYPE) == N_SECT))
		return (is_ext_64(array, get_seg_type_64(array, ptr)));
	if (((endian_2(array.n_type) & N_TYPE) == N_UNDF))
		return (is_ext_64(array, ((endian_8(array.n_value) == 0) ? 'u' : 'c')));
	if (((endian_2(array.n_type) & N_TYPE) == N_ABS))
		return (is_ext_64(array, 'a'));
	if (((endian_2(array.n_type) & N_TYPE) == N_INDR))
		return (is_ext_64(array, 'i'));
	return (is_ext_64(array, '?'));
}
