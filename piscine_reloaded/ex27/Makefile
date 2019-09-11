# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 15:07:01 by cwheatgr          #+#    #+#              #
#    Updated: 2019/09/04 16:51:15 by cwheatgr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

SRC = ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/main.c

HEADER = ./includes/

GCC = gcc -Wall -Wextra -Werror

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME):
	$(GCC) -o $(NAME) $(SRC) -I $(HEADER)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
