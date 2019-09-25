/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 20:52:53 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/11 23:21:07 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		main(int argc, char **argv)
{
	char	desk[9][9];

	if (s_wrong_arg(argc, argv) != 0)
	{
		s_read_desk(argv, desk);
		if (s_troubles(desk) == 0)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		else if (s_solution(0, 0, desk) == 1)
			s_write_desk(desk);
		else
			write(1, "Error\n", 6);
	}
	return (0);
}
