# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knarwhal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/13 12:30:16 by knarwhal          #+#    #+#              #
#    Updated: 2019/08/19 15:09:39 by knarwhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
HEADER = ./includes/
SRCS = ./srcs/*.c
FLAGS = -Wall -Wextra -Werror

.PHONY: all $(NAME) cean fclean re

all: $(NAME)

$(NAME):
		gcc $(FLAGS) -I $(HEADER) $(SRCS) -o $(NAME)

clean:
		/bin/rm -f $(NAME)

fclean: clean

re: clean all
