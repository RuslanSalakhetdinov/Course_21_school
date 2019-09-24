# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/20 20:25:24 by cwheatgr          #+#    #+#              #
#    Updated: 2019/09/24 20:22:58 by cwheatgr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_bzero ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint \
	  ft_itoa ft_lstadd ft_lstdel ft_lstdelone ft_lstiter ft_lstmap ft_lstnew \
	  ft_memalloc ft_memccpy ft_memchr ft_memcmp ft_memcpy ft_memdel ft_atoi \
	  ft_memmove ft_memset ft_putchar ft_putchar_fd ft_putendl ft_putendl_fd \
	  ft_putnbr ft_putnbr_fd ft_putstr ft_putstr_fd ft_strcat ft_strchr \
	  ft_strclr ft_strcmp ft_strcpy ft_strdel ft_strequ ft_striter ft_strsub \
	  ft_striteri ft_strjoin ft_strlcat ft_strlen ft_strmap ft_strmapi \
	  ft_strncat ft_strncmp ft_strncpy ft_strnew ft_strnstr ft_strrchr \
	  ft_strsplit ft_strstr ft_strtrim ft_tolower ft_toupper ft_strdup \
	  ft_strnequ

HEADER = libft.h

C_FILES = $(patsubst %, %.c, $(SRCS))

O_FILES = $(patsubst %, %.o, $(SRCS))

FLAGS = -Wall -Wextra -Werror -Ofast -c

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(O_FILES) $(HEADER)
	ar rc $(NAME) $?
	ranlib $(NAME)

$(O_FILES): %.o: %.c
	gcc $(FLAGS) $?

clean:
	/bin/rm -f $(O_FILES)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
