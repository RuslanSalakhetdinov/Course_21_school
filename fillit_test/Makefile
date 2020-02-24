# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwheatgr <cwheatgr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/19 20:36:35 by aquill            #+#    #+#              #
#    Updated: 2020/02/20 22:32:33 by cwheatgr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

CC		= gcc
CFLAGS 	= -Wall -Wextra -Werror

SRC_DIR = ./srcs/
INC_DIR	= ./inc/
OBJ_DIR = ./obj/
LIB_DIR	= ./libft/

SRC = $(addprefix $(SRC_DIR),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_DIR),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_DIR))

SRC_NAME	:=	beyond_borders.c \
	board_free.c \
	board_new.c \
	board_output.c \
	board_size.c \
	change_symbols.c \
	form_alignment.c \
	form_count.c \
	form_new.c \
	if_overlap.c \
	is_it_tetra.c \
	solution.c \
	solve_algorithm.c \
	parser.c \
	get_next_line.c \
	read_and_check.c \
	form_free.c \
	main.c

OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = fillit.h

.PHONY: all $(NAME) clean re fclean

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_DIR)
	@$(CC) $(OBJ) -L $(LIB_DIR) -l ft -o $(NAME)
	@echo "[Information:] fillit_was_created"

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -I$(LIB_DIR) -o $@ -c $<

clean:
	@make -C $(LIB_DIR) clean
	rm -rf $(OBJ_DIR)
	@echo "[Information:] Object_folder_was_removed"

fclean: clean
	@make -C $(LIB_DIR) fclean
	rm -rf $(NAME)
	@echo "[Information:] Exe_file_was_removed"

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory