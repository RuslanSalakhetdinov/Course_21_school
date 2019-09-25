# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/18 14:50:44 by cwheatgr          #+#    #+#              #
#    Updated: 2019/08/18 14:58:59 by cwheatgr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr

SRC = srcs/*.c

HEADER = includes/

GCC = gcc -Wall -Wextra -Werror

.PHONY: all
all: $(NAME)

$(NAME):
	$(GCC) $(SRC) -o $(NAME) -I $(HEADER)

.PHONY: clean
clean:
	/bin/rm -f $(NAME)

.PHONY: re
re: clean all

