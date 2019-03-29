/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:31:58 by nhaquet           #+#    #+#             */
/*   Updated: 2018/10/30 18:36:29 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_nm.h"
#include <stdio.h>

int		switch_arch(unsigned int fat_magic, void *newptr, void *endptr)
{
	if (fat_magic == MH_MAGIC_64 || fat_magic == MH_CIGAM_64)
	{
		endian_little_mode(fat_magic == MH_CIGAM_64);
		handle_64(newptr, endptr);
		return (1);
	}
	if (fat_magic == MH_MAGIC || fat_magic == MH_CIGAM)
	{
		endian_little_mode(fat_magic == MH_CIGAM);
		handle_32(newptr, endptr);
		return (2);
	}
	return (0);
}

int		handle_arch_64(uint32_t nfat_arch, size_t offset, void *ptr, \
	void *endptr)
{
	struct fat_arch_64	*farch;
	unsigned int		fat_magic;
	void				*newptr;

	farch = ptr + offset;
	while (nfat_arch--)
	{
		if ((void*)farch > endptr)
			return (-2);
		fat_magic = *(unsigned int *)(ptr + endian_8(farch->offset));
		newptr = (ptr + endian_8(farch->offset));
		if (switch_arch(fat_magic, newptr, endptr))
			break ;
		farch = (void *)farch + sizeof(struct fat_arch);
	}
	return (0);
}

int		handle_arch_32(uint32_t nfat_arch, size_t offset, void *ptr, \
	void *endptr)
{
	struct fat_arch	*farch;
	unsigned int	fat_magic;
	void			*newptr;

	farch = ptr + offset;
	while (nfat_arch--)
	{
		if ((void*)farch > endptr)
			return (-2);
		fat_magic = *(unsigned int *)(ptr + endian_4(farch->offset));
		newptr = (ptr + endian_4(farch->offset));
		if (switch_arch(fat_magic, newptr, endptr))
			break ;
		farch = (void *)farch + sizeof(struct fat_arch);
	}
	return (0);
}

int		handle_fat(void *ptr, void *endptr, bool is_64)
{
	struct fat_header		*header;

	header = (struct fat_header *)ptr;
	if (is_64)
	{
		return (handle_arch_64(endian_4(header->nfat_arch) \
		, sizeof(struct fat_header), ptr, endptr));
	}
	else
	{
		return (handle_arch_32(endian_4(header->nfat_arch) \
		, sizeof(struct fat_header), ptr, endptr));
	}
	return (0);
}
