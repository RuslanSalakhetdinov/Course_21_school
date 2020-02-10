/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:05:27 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/02/10 14:43:41 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		solution(t_form *form)
{
	int		b_size;
	t_board	*board;

	b_size = board_size(form_count(form) * 4);
	board = board_new(b_size);
	while (!solve_algorithm(board, form))
	{
		board_free(board);
		b_size++;
		board = board_new(b_size);
	}
	board_output(board);
	board_free(board);
}
