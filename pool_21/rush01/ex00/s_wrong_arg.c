/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_wrong_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbarathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 17:22:48 by pbarathe          #+#    #+#             */
/*   Updated: 2019/08/11 23:05:08 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		check(int i, int j, int argc, char **argv)
{
	while (i < argc)
	{
		while (argv[i][j] != '\0')
		{
			if (ft_strlen(argv[i]) != 9)
			{
				write(1, "Error\n", 6);
				return (0);
			}
			if (argv[i][j] > '1' || argv[i][j] < '9' || argv[i][j] == '.')
				j++;
			else
			{
				write(1, "Error\n", 6);
				return (0);
			}
		}
		i++;
		j = 0;
	}
	return (1);
}

int		s_wrong_arg(int argc, char **argv)
{
	int i;
	int j;

	j = 0;
	i = 1;
	if (argc == 10)
		if (check(i, j, argc, argv) == 1)
			return (1);
	write(1, "Error\n", 6);
	return (0);
}
