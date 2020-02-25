/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 22:18:44 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/02/25 01:29:18 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			valid_main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
	{
		ft_putstr("usage ./fillit [input_file]");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY) < 0))
	{
		ft_putstr("error\n");
		return (0);
	}
	close(fd);
	if (read_blocks_for_check(argv) != 1)
	{
		ft_putstr("error\n");
		return (0);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	int		fd;
	char	symbol;

	symbol = 'A';
	if (!valid_main(argc, argv))
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (get_tetraminos_form(fd, symbol) != 1)
	{
		ft_putstr("error\n");
		return (-1);
	}
	close(fd);
	return (1);
}
