# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/12 17:23:17 by cwheatgr          #+#    #+#              #
#    Updated: 2019/08/13 20:05:31 by cwheatgr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c \
	  ./srcs/ft_strlen.c ./srcs/ft_swap.c

OFILES = ft_putchar.o ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

GCCFLAGES = gcc -Wall -Wextra -Werror

HEADER = ./includes/

.PHONY: all
all: $(NAME)

$(NAME):
	$(GCCFLAGES) -c $(SRC) -I $(HEADER)
	ar rc $(NAME) $(OFILES)
	ranlib $(NAME)

.PHONY: clean
clean:
	/bin/rm -f $(OFILES)

.PHONY: fclean
fclean: clean
	/bin/rm -f $(NAME)

.PHONY: re
re: fclean all
