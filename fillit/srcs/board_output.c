/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:42:52 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/02/10 16:45:07 by cwheatgr         ###   ########.fr       */
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
