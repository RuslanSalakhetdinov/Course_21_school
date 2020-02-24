/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 22:18:44 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/02/24 22:48:21 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int			main(int argc, char **argv)
{
	int		fd;
	char	symbol;

	symbol = 'A';
	if (argc != 2)
	{
		ft_putstr("usage ./fillit [input_file]");
		return (-1);
	}
	if (read_blocks_for_check(argv) != 1)
	{
		ft_putstr("error\n");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (get_tetraminos_form(fd, symbol) != 1)
	{
		ft_putstr("error\n");
		return (-1);
	}
	close(fd);
	return (1);
}
