/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_addr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 14:56:46 by nhaquet           #+#    #+#             */
/*   Updated: 2018/10/30 18:33:07 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_nm.h"
#include <stdlib.h>

char	*put_tab(char type, uint64_t value, uint32_t ftype, uint32_t size)
{
	char	*str;
	char	*istr;
	int		i;
	int		j;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	bzero(str, size + 1);
	if (type == 'U' || type == 'u')
	{
		str = ft_memset(str, ' ', size);
		return (str);
	}
	istr = ft_itoa_base(value, 16);
	i = ft_strlen(istr) + 1;
	j = size;
	ft_memset(str, '0', size);
	while (--i >= 0)
		str[j--] = istr[i];
	if (ftype == MH_EXECUTE && size == 16)
		str[7] = '1';
	free(istr);
	return (str);
}

t_data	*get_addr(struct nlist array, t_file *fdata)
{
	t_data	*data;

	if (!(data = malloc(sizeof(t_data))))
		return (NULL);
	data->type = get_type(array, fdata->ptr);
	data->value = put_tab(data->type, endian_4(array.n_value), fdata->ftype, 8);
	data->name = fdata->stab + endian_4(array.n_un.n_strx);
	return (data);
}

t_data	*get_addr_64(struct nlist_64 array, t_file *fdata)
{
	t_data *data;

	if (!(data = malloc(sizeof(t_data))))
		return (NULL);
	data->type = get_type_64(array, fdata->ptr);
	data->value = put_tab(data->type, endian_8(array.n_value) \
		, fdata->ftype, 16);
	data->name = fdata->stab + endian_4(array.n_un.n_strx);
	return (data);
}
