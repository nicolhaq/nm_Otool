/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 17:48:44 by nhaquet           #+#    #+#             */
/*   Updated: 2018/10/30 18:56:07 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_nm.h"

void	print_symb(t_data **darray)
{
	int	i;

	i = 0;
	while (darray[i] != NULL)
	{
		if ((darray[i]->name[0] != '/') && (darray[i]->name[0] != '\0'))
		{
			ft_putstr(darray[i]->value);
			ft_putchar(' ');
			ft_putchar(darray[i]->type);
			ft_putchar(' ');
			ft_putstr(darray[i]->name);
			ft_putchar('\n');
		}
		i++;
	}
}

int		test_nlist(struct nlist *array, struct nlist_64 *array_64, int i \
					, void *endptr)
{
	if ((((void *)array_64 + sizeof(struct nlist_64) * (1 + i)) > endptr) \
		|| (((void *)array + sizeof(struct nlist) * (1 + i)) > endptr))
		return (-2);
	return (0);
}

int		print_output(t_file *fdata, int is_64, void *endptr)
{
	unsigned int	i;
	struct nlist	*array;
	struct nlist_64 *array_64;
	t_data			**darray;

	i = 0;
	array = (void *)fdata->ptr + endian_4(fdata->sym->symoff);
	array_64 = (void *)fdata->ptr + endian_4(fdata->sym->symoff);
	if (!(darray = malloc(sizeof(t_data) * (endian_4(fdata->sym->nsyms) + 1))))
		return (-1);
	while (i < endian_4(fdata->sym->nsyms))
	{
		if (test_nlist(array, array_64, i, endptr))
			return (-2);
		if (is_64)
			darray[i] = get_addr_64(array_64[i], fdata);
		else
			darray[i] = get_addr(array[i], fdata);
		i++;
	}
	darray[i] = NULL;
	sort_array(darray, 0, i - 1);
	print_symb(darray);
	free_tab(darray);
	return (0);
}

void	print_file(int argc, char **argv, int i)
{
	if (argc > 2)
	{
		ft_putchar('\n');
		ft_putstr(argv[i]);
		ft_putstr(":\n");
	}
}
