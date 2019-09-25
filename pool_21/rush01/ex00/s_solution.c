/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_solution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 20:27:51 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/11 23:19:52 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		s_solution(int x, int y, char desk[9][9])
{
	char digit;

	digit = '0';
	if (desk[x][y] != '0')
	{
		if (y == 9)
			return (1);
		if (y == 8 && s_solution(x + 1, 0, desk))
			return (1);
		else if (s_solution(x, y + 1, desk))
			return (1);
	}
	while (++digit <= '9')
		if (s_valid(x, y, desk, digit))
		{
			desk[x][y] = digit;
			if (y == 8 && s_solution(x + 1, 0, desk))
				return (1);
			if (s_solution(x, y + 1, desk))
				return (1);
			desk[x][y] = '0';
		}
	return (0);
}
