/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_troubles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 23:05:20 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/11 23:30:27 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		s_troubles(char desk[9][9])
{
	int i;
	int j;
	int counter;

	counter = 0;
	i = -1;
	while (++i < 9)
	{
		j = -1;
		while (++j < 9)
		{
			if (desk[i][j] != '0')
			{
				counter++;
			}
		}
	}
	if (counter < 17)
		return (0);
	return (1);
}
