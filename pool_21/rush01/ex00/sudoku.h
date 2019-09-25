/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 21:37:24 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/11 23:15:34 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H
# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(char *str);
int		s_valid(int row, int column, char desk[9][9], char num);
void	s_write_desk(char desk[9][9]);
int		s_troubles(char desk[9][9]);
int		s_wrong_arg(int argc, char **argv);
void	s_read_desk(char **argv, char desk[9][9]);
int		s_solution(int x, int y, char desk[9][9]);

#endif
