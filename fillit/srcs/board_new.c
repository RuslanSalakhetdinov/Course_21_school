/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:23:20 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/02/10 16:33:39 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_board		*board_new(int b_size)
{
	t_board	*board;
	int		i;

	board = (t_board*)malloc(sizeof(t_board));
	board->map = (char**)malloc(sizeof(char*) * b_size);
	i = 0;
	while (i < b_size)
	{
		board->map[i] = ft_strnew(b_size);
		ft_memset(board->map[i], '.', b_size);
		i++;
	}
	return (board);
}
