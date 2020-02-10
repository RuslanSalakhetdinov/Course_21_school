/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_overlap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:20:24 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/02/10 15:36:32 by cwheatgr         ###   ########.fr       */
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
		num++;
		x_pos = form->pos[num][0] + form->x_base;
		y_pos = form->pos[num][1] + form->y_base;
	}
	if (num == 3)
		return (1);
	else
		return (0);
}
