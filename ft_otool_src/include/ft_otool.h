/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 19:51:37 by nhaquet           #+#    #+#             */
/*   Updated: 2018/11/06 13:40:18 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OTOOL_H
# define FT_OTOOL_H
# include <fcntl.h>
# include <sys/mman.h>
# include <sys/stat.h>
# include <mach-o/fat.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include "../../libft/libft.h"
# include <stdbool.h>

typedef struct	s_data
{
	char	type;
	char	*name;
	char	*value;
}				t_data;

typedef struct	s_file
{
	char					*stab;
	char					*ptr;
	uint32_t				ftype;
	struct symtab_command	*sym;
}				t_file;

void			byte_to_hex(char byte);
void			ptr_to_hex(size_t ptr, boolean_t len64);
char			get_type(struct nlist array, char *ptr);
int				get_seg_type_64(char *ptr, void *endptr);
int				get_seg_type(char *ptr, void *endptr);
t_data			*get_addr(struct nlist array, t_file *fdata);
t_data			*get_addr_64(struct nlist_64 array, t_file *fdata);
void			ft_parse(char **argv, int argc);
int				handle_32(void *ptr, void *endptr);
int				handle_64(void *ptr, void *endptr);
int				handle_fat(void *ptr, void *endptr, bool is_64);
int				file_handler(char *ptr, struct stat *buf);
int				print_output(t_file *fdata, int is_64, void *endptr);
void			print_file(int argc, char **argv, int i);
void			endian_little_mode(bool is_little_endian);
uint16_t		endian_2(uint16_t n);
uint32_t		endian_4(uint32_t n);
uint64_t		endian_8(uint64_t n);

#endif
