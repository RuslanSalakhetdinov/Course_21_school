# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwheatgr <cwheatgr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/20 20:25:24 by cwheatgr          #+#    #+#              #
#    Updated: 2020/02/25 01:34:31 by cwheatgr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_bzero ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint \
	  ft_itoa ft_lstadd ft_lstdel ft_lstdelone ft_lstiter ft_lstmap ft_lstnew \
	  ft_memalloc ft_memccpy ft_memchr ft_memcmp ft_memcpy ft_memdel ft_atoi \
	  ft_memmove ft_memset ft_putchar ft_putchar_fd ft_putendl ft_putendl_fd \
	  ft_putnbr ft_putnbr_fd ft_putstr ft_putstr_fd ft_strcat ft_strchr \
	  ft_strclr ft_strcmp ft_strcpy ft_strdel ft_strequ ft_striter ft_strsub \
	  ft_striteri ft_strjoin ft_strlen ft_strmap ft_strmapi \
	  ft_strncat ft_strncmp ft_strncpy ft_strnew ft_strnstr ft_strrchr \
	  ft_strsplit ft_strstr ft_strtrim ft_tolower ft_toupper ft_strdup \
	  ft_strnequ

MY_SRCS = ft_istrlower ft_istrupper ft_swap ft_strcapitalize ft_strrcapitalize

HEADER = ./../includes/libft.h

INC_DIR	= ./../includes/

C_FILES = $(patsubst %, %.c, $(SRCS))

C_MY_FILES = $(patsubst %, %.c, $(MY_SRCS))

O_FILES = $(patsubst %, %.o, $(SRCS))

O_MY_FILES = $(patsubst %, %.o, $(MY_SRCS))

INC = $(addprefix -I,$(INC_DIR))

FLAGS = -Wall -Wextra -Werror -Ofast -c

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(O_FILES) $(O_MY_FILES) $(HEADER)
	@ar rc $(NAME) $?
	@ranlib $(NAME)

$(O_FILES) $(O_MY_FILES): %.o: %.c
	@gcc $(FLAGS) $(INC) $?

clean:
	@/bin/rm -f $(O_FILES) $(O_MY_FILES)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
