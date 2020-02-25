/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:45:53 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/02/25 01:27:07 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		solve_algorithm(t_board *board, t_form *form)
{
	if (!form)
		return (1);
	form->x_base = 0;
	form->y_base = 0;
	while (beyond_borders(form, board->size, -42))
	{
		while (beyond_borders(form, board->size, 0))
		{
			if (if_overlap(board, form))
			{
				change_symbols(board, form, form->symbol);
				if (solve_algorithm(board, form->next))
					return (1);
				else
					change_symbols(board, form, '.');
			}
			(form->x_base)++;
		}
		form->x_base = 0;
		(form->y_base)++;
	}
	return (0);
}
