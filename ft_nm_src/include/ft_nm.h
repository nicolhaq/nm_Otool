/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 19:51:37 by nhaquet           #+#    #+#             */
/*   Updated: 2018/10/30 18:22:06 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H
# include <fcntl.h>
# include <sys/mman.h>
# include <sys/stat.h>
# include <mach-o/fat.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <stdbool.h>
# include "../../libft/libft.h"

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

char			get_type(struct nlist array, char *ptr);
char			get_type_64(struct nlist_64 array, char *ptr);
t_data			*get_addr(struct nlist array, t_file *fdata);
t_data			*get_addr_64(struct nlist_64 array, t_file *fdata);
void			ft_parse(char **argv, int argc);
int				handle_32(char *ptr, void *endptr);
int				handle_64(char *ptr, void *endptr);
int				handle_fat(void *ptr, void *endptr, bool is_64);
void			print_symb(t_data **darray);
int				print_output(t_file *fdata, int is_64, void *endptr);
void			print_file(int argc, char **argv, int i);
void			sort_array(t_data **darray, int begin, int end);
void			free_tab(t_data **darray);
void			endian_little_mode(bool is_little_endian);
uint16_t		endian_2(uint16_t n);
uint32_t		endian_4(uint32_t n);
uint64_t		endian_8(uint64_t n);
#endif
