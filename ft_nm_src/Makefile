# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/21 16:37:00 by nhaquet           #+#    #+#              #
#    Updated: 2018/10/30 18:54:14 by nhaquet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = src/
SRC_NAME =	ft_nm.c get_type.c get_addr.c parser.c get_type_64.c handle.c \
			print.c sort.c free_tab.c fat.c endian.c
OBJ_PATH = obj/
CPPFLAGS = -Iinclude
LDFLAGS = -L../libft
LDLIBS = -lft
NAME = ft_nm
CC = clang
CFLAGS = -Wall -Wextra -Werror
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH),$(SRC_NAM))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re