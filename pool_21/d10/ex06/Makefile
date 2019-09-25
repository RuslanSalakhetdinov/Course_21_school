# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/13 16:05:05 by cwheatgr          #+#    #+#              #
#    Updated: 2019/08/18 14:59:28 by cwheatgr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

SRC = ./srcs/ft_add.c ./srcs/ft_sub.c ./srcs/ft_div.c ./srcs/ft_mod.c \
	  ./srcs/ft_mul.c ./srcs/main.c ./srcs/ft_atoi.c ./srcs/ft_putnbr.c \
	  ./srcs/ft_putchar.c ./srcs/ft_valid.c

HEADER = ./includes/

GCC = gcc -Wall -Wextra -Werror

.PHONY: all
all: $(NAME)

$(NAME):
@	$(GCC) $(SRC) -o $(NAME) -I $(HEADER)

.PHONY: clean
clean:
@	/bin/rm -f $(NAME)

.PHONY: fclean
fclean: clean

.PHONY: re
re: fclean all
