/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 14:52:38 by nhaquet           #+#    #+#             */
/*   Updated: 2018/10/18 16:47:10 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_nm.h"

char	sec_symb(struct segment_command	*seg, int n)
{
	struct section		*sect;

	sect = (struct section *)((char *)seg
		+ sizeof(struct segment_command));
	sect = sect + n;
	if (!ft_strcmp(sect->sectname, "__data"))
		return ('d');
	else if (!ft_strcmp(sect->sectname, "__bss"))
		return ('b');
	else if (!ft_strcmp(sect->sectname, "__text"))
		return ('t');
	return ('s');
}

char	get_seg_type(struct nlist array, char *ptr)
{
	struct mach_header		*header;
	struct load_command		*lc;
	struct segment_command	*seg;
	unsigned int			i;
	int						n;

	i = 0;
	n = 0;
	header = (struct mach_header *)ptr;
	lc = (void *)ptr + sizeof(*header);
	while (i < endian_4(header->ncmds))
	{
		if (endian_4(lc->cmd) == LC_SEGMENT)
		{
			seg = (struct segment_command *)lc;
			if ((endian_4(seg->nsects) + n) >= endian_2(array.n_sect))
				return (sec_symb(seg, endian_2(array.n_sect) - n - 1));
			n = n + endian_4(seg->nsects);
		}
		lc = (struct load_command *)(((char *)lc) + endian_4(lc->cmdsize));
		i++;
	}
	return ('s');
}

char	is_ext(struct nlist array, char c)
{
	if (((endian_2(array.n_type) & N_EXT) && (c != ' ')))
		c = ft_toupper(c);
	return (c);
}

char	get_type(struct nlist array, char *ptr)
{
	if (N_STAB & endian_2(array.n_type))
		return ('-');
	else if ((endian_2(array.n_type) & N_TYPE) == N_SECT)
		return (is_ext(array, get_seg_type(array, ptr)));
	else if ((endian_2(array.n_type) & N_TYPE) == N_UNDF)
		return (is_ext(array, ((endian_4(array.n_value) == 0) ? 'u' : 'c')));
	else if ((endian_2(array.n_type) & N_TYPE) == N_ABS)
		return (is_ext(array, 'a'));
	else if ((endian_2(array.n_type) & N_TYPE) == N_INDR)
		return (is_ext(array, 'i'));
	else if ((endian_2(array.n_type) & N_TYPE) == N_PBUD)
		return (is_ext(array, 'u'));
	return (is_ext(array, '?'));
}
