/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:42:52 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/02/25 01:24:43 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	board_output(t_board *board)
{
	int	i;

	i = 0;
	while (i < board->size)
	{
		ft_putstr(board->map[i]);
		ft_putchar('\n');
		i++;
	}
}
