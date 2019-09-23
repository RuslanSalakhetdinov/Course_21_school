/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_valid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syesseni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 17:27:05 by syesseni          #+#    #+#             */
/*   Updated: 2019/08/11 23:27:05 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		s_valid(int row, int column, char desk[9][9], char num)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 9)
		if (desk[i][column] == num || desk[row][i] == num)
			return (0);
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			if (desk[row - (row % 3) + i][column - (column % 3) + j] == num)
				return (0);
	}
	return (1);
}
