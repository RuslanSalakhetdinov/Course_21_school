/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_symbols.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:29:40 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/02/10 15:35:35 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	change_symbols(t_board *board, t_form *form, char symbol)
{
	int	num;
	int	x_pos;
	int	y_pos;

	num = 0;
	while (num < 4)
	{
		x_pos = form->pos[num][0] + form->x_base;
		y_pos = form->pos[num][1] + form->y_base;
		board->map[y_pos][x_pos] = symbol;
		num++;
	}
}
