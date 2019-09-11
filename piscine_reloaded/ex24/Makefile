# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 14:15:23 by cwheatgr          #+#    #+#              #
#    Updated: 2019/09/05 16:28:02 by cwheatgr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c \
	   ./srcs/ft_strlen.c ./srcs/ft_swap.c

OF = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

GCC = gcc -Wall -Wextra -Werror

HEADER = ./includes/

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME):
	$(GCC) -c $(SRC) -I $(HEADER)
	ar rc $(NAME) $(OF)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OF)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
