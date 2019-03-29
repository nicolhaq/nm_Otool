/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 15:29:34 by evignol           #+#    #+#             */
/*   Updated: 2016/02/23 16:01:58 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFF_SIZE 512

typedef struct			s_listo
{
	char				*buff;
	int					fd;
	struct s_listo		*first;
	struct s_listo		*next;
}						t_listo;

int						get_next_line(int fd, char **line);

#endif
