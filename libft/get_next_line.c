/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 15:29:28 by evignol           #+#    #+#             */
/*   Updated: 2018/05/11 11:47:03 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_strkcat(char *dest, const char *src)
{
	unsigned int	i;
	unsigned int	j;
	char			*orig;

	orig = dest;
	i = 0;
	while (dest[i] != '\00')
		i++;
	j = 0;
	while (src[j] != '\n')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\00';
	return (orig);
}

static void			ft_rewind(char *str, char *pos)
{
	unsigned int	i;

	i = 0;
	while (*(pos + i + 1) != '\00')
	{
		str[i] = *(pos + i + 1);
		i++;
	}
	str[i] = '\00';
}

static int			ft_get_next3(char **line, char *buff, int fd, int ret)
{
	char		*tmp;

	while (ret > 0)
	{
		if (buff[0] == '\00')
		{
			if (!(tmp = ft_memalloc(BUFFF_SIZE + 1)))
				return (-1);
			ret = read(fd, tmp, BUFFF_SIZE);
			ft_strncat(buff, tmp, ret);
			ft_memdel((void **)(&tmp));
		}
		if (ret == 0 && buff[0] == '\00')
			return (0);
		*line = ft_realloc(*line, ft_strlen(*line) + ret + 1);
		if (ft_strchr(buff, '\n'))
		{
			ft_strkcat(*line, buff);
			ft_rewind(buff, ft_strchr(buff, '\n'));
			return (1);
		}
		ft_strcat(*line, buff);
		ft_bzero(buff, BUFFF_SIZE + 1);
	}
	return (-1);
}

static t_listo		*getgoodbox(t_listo *list, int fd)
{
	list = list->first;
	while (list->next)
	{
		if (list->fd == fd)
			return (list);
		list = list->next;
	}
	if (list->fd == fd)
		return (list);
	if (!(list->next = (t_listo *)malloc(sizeof(t_listo))))
		return (NULL);
	list->next->first = list->first;
	list = list->next;
	list->fd = fd;
	list->buff = ft_memalloc(BUFFF_SIZE + 1);
	list->next = NULL;
	return (list);
}

int					get_next_line(int fd, char **line)
{
	static t_listo		*box = NULL;
	int					ret;

	if (!box)
	{
		if (!(box = (t_listo*)malloc(sizeof(t_listo))))
			return (-1);
		box->first = box;
		box->fd = fd;
		box->buff = ft_memalloc(BUFFF_SIZE + 1);
		box->next = NULL;
	}
	else
		box = getgoodbox(box, fd);
	ret = 1;
	if (fd < 0 || line == NULL || box == NULL || box->buff == NULL)
		return (-1);
	*line = NULL;
	if ((*line = ft_memalloc(BUFFF_SIZE + 1)) == NULL)
		return (-1);
	ret = ft_get_next3(line, box->buff, box->fd, ret);
	return (ret);
}
