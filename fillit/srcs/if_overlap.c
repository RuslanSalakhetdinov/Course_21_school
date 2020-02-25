/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_overlap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:20:24 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/02/25 01:25:58 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		if_overlap(t_board *board, t_form *form)
{
	int	num;
	int	x_pos;
	int	y_pos;

	num = 0;
	x_pos = form->pos[num][0] + form->x_base;
	y_pos = form->pos[num][1] + form->y_base;
	while (num < 4 && board->map[y_pos][x_pos] == '.')
	{
		x_pos = form->pos[num][0] + form->x_base;
		y_pos = form->pos[num][1] + form->y_base;
		num++;
	}
	if (num == 4 && board->map[y_pos][x_pos] == '.')
		return (1);
	else
		return (0);
}
