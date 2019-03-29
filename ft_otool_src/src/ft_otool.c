/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:36:29 by nhaquet           #+#    #+#             */
/*   Updated: 2018/11/06 13:56:46 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_otool.h"

int		otool_init(char **ptr, struct stat *buf, char *argv)
{
	int				fd;

	if ((fd = open(argv, O_RDONLY)) < 0)
	{
		ft_putstr("error: could not open the file\n");
		return (-1);
	}
	if ((fstat(fd, buf)))
	{
		ft_putstr("error: fstat error\n");
		return (-1);
	}
	if (!S_ISREG(buf->st_mode))
	{
		ft_putstr("error: not a file\n");
		return (-1);
	}
	if (!(*ptr = mmap(0, buf->st_size, PROT_READ, MAP_PRIVATE, fd, 0)))
	{
		ft_putstr("error: mmap fail\n");
		return (-1);
	}
	return (fd);
}

int		put_error(int ret)
{
	if (ret == -2)
		ft_putstr("error: file truncated or corrupted\n");
	if (ret == -1)
		ft_putstr("error: architecture not supported\n");
	return (ret);
}

int		file_handler(char *ptr, struct stat *buf)
{
	unsigned int	magic_number;
	void			*endptr;
	int				ret;

	ret = 0;
	endptr = ((void *)ptr + buf->st_size);
	magic_number = *(int *)ptr;
	endian_little_mode(magic_number == MH_CIGAM_64 \
		|| magic_number == MH_CIGAM || magic_number == FAT_CIGAM_64 \
		|| magic_number == FAT_CIGAM);
	if (magic_number == MH_MAGIC_64 || magic_number == MH_CIGAM_64)
		ret = handle_64((void *)ptr, endptr);
	else if (magic_number == MH_MAGIC || magic_number == MH_CIGAM)
		ret = handle_32((void *)ptr, endptr);
	else if (magic_number == FAT_MAGIC_64 || magic_number == FAT_CIGAM_64)
		ret = handle_fat((void *)ptr, endptr, true);
	else if (magic_number == FAT_MAGIC || magic_number == FAT_CIGAM)
		ret = handle_fat((void *)ptr, endptr, false);
	else
		return (-1);
	return (ret);
}

int		main(int argc, char **argv)
{
	int			fd;
	char		*ptr;
	struct stat	buf;
	int			i;

	fd = 0;
	i = 0;
	ft_parse(argv, argc);
	while (argv[i] != NULL)
	{
		if ((fd = otool_init(&ptr, &buf, argv[i])) < 0)
			return (1);
		print_file(argc, argv, i);
		if (put_error(file_handler(ptr, &buf)) < 0)
			return (-1);
		if (munmap(ptr, buf.st_size))
		{
			ft_putstr("error: munmap fail\n");
			return (1);
		}
		close(fd);
		i++;
	}
	return (0);
}
