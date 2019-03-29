/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 12:11:52 by nhaquet           #+#    #+#             */
/*   Updated: 2018/11/06 15:20:16 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_nm.h"

void	init_struct(t_file *fdata, struct symtab_command	*sym, char *ptr,
					uint32_t ftype)
{
	fdata->stab = (void *)ptr + endian_4(sym->stroff);
	fdata->ptr = ptr;
	fdata->ftype = ftype;
	fdata->sym = sym;
}

int		handle_32(char *ptr, void *endptr)
{
	unsigned int			i;
	struct mach_header		*header;
	struct load_command		*lc;
	struct symtab_command	*sym;
	t_file					fdata;

	header = (struct mach_header *)ptr;
	i = 0;
	lc = (void *)ptr + sizeof(struct mach_header);
	while (i < endian_4(header->ncmds))
	{
		if ((((void*)lc + sizeof(struct load_command )) > endptr) \
			&& (((void*)lc + sizeof(struct load_command ) \
			+ sizeof(struct symtab_command)) > endptr))
			return (-2);
		if (endian_4(lc->cmd) == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			init_struct(&fdata, sym, ptr, endian_4(header->filetype));
			print_output(&fdata, 0, endptr);
		}
		lc = (void *)lc + endian_4(lc->cmdsize);
		i++;
	}
	return (0);
}

int		handle_64(char *ptr, void *endptr)
{
	unsigned int			i;
	struct mach_header_64	*header;
	struct load_command		*lc;
	struct symtab_command	*sym;
	t_file					fdata;

	header = (struct mach_header_64 *)ptr;
	i = 0;
	lc = (void *)ptr + sizeof(struct mach_header_64);
	while (i < endian_4(header->ncmds))
	{
		if ((((void*)lc + sizeof(struct load_command )) > endptr) \
			&& (((void*)lc + sizeof(struct load_command ) \
			+ sizeof(struct symtab_command)) > endptr))
			return (-2);
		if (endian_4(lc->cmd) == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			init_struct(&fdata, sym, ptr, endian_4(header->filetype));
			return (print_output(&fdata, 1, endptr));
		}
		lc = (void *)lc + endian_4(lc->cmdsize);
		i++;
	}
	return (0);
}
