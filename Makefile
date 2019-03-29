# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/29 18:06:11 by nhaquet           #+#    #+#              #
#    Updated: 2018/10/26 15:00:33 by nhaquet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = ft_nm , ft_otool

all: lib $(NAME)

$(NAME):
	make -C ft_nm_src
	make -C ft_otool_src
	mv ft_nm_src/ft_nm .
	mv ft_otool_src/ft_otool .

clean: 
	make -C ft_nm_src clean
	make -C ft_otool_src clean

fclean: clean libfclean 
	make -C ft_nm_src fclean
	make -C ft_otool_src fclean
	rm ft_nm
	rm ft_otool

re: fclean libfclean all

lib:
	make -C libft

libfclean:
	make -C libft fclean

.PHONY: all, clean, fclean, re