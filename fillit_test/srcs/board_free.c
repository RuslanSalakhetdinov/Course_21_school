/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:33:52 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/02/24 20:02:24 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	board_free(t_board *board)
{
	int	i;

	i = 0;
	while (i < board->size)
	{
		free(board->map[i]);
		i++;
	}
	free(board->map);
	free(board);
}
