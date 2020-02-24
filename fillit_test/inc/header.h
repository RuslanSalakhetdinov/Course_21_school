/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 22:09:47 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/02/24 22:49:01 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define BUFF_SIZE	256

typedef struct			s_form
{
	int					pos[4][2];
	char				symbol;
	int					x_base;
	int					y_base;
	struct s_form		*next;
}						t_form;

typedef struct			s_board
{
	char				**map;
	int					size;
}						t_board;

int						check_line(const int fd, char **line, char **str, \
		ssize_t read_bytes);
int						get_next_line(const int fd, char **line);
t_form					*form_new(char *buf, char symbol);
int						beyond_borders(t_form *form, int b_size, int flag);
void					board_free(t_board *board);
t_board					*board_new(int b_size);
void					board_output(t_board *board);
int						board_size(int size);
void					change_symbols(t_board *board, \
		t_form *form, char symbol);
t_form					*form_alignment(t_form *form);
int						form_count(t_form *form);
int						if_overlap(t_board *board, t_form *form);
int						is_it_tetra(char *buf);
void					solution(t_form *form);
int						solve_algorithm(t_board *board, t_form *form);
int						read_blocks_for_check(char **argv);
int						check_simbols(char *str);
char					*get_tetramino(int fd, char *tetraminoshka);
int						get_tetraminos_form (int fd, char symbol);
void					form_free(t_form **head);

#endif
