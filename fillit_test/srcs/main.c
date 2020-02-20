/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mian.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 01:02:53 by lgunship          #+#    #+#             */
/*   Updated: 2020/02/19 14:49:36 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
	{
		ft_putstr("usage ./fillit [input_file]");
		return (-1);
	}
	if ((fd = open(argv[1], O_RDONLY) == -1))
	{
		ft_putstr("error");
		return (1);
	}
	close(fd);
	if (read_blocks_for_check(argv) != 1)
	{
		ft_putstr("error1");
		return (-1);
	}
	if ((fd = open(argv[1], O_RDONLY) == -1))
		return (-1);
	if (get_tetraminos_form(fd) != 1)
	{
		ft_putstr("error2");
		return (-1);
	}
	close(fd);
	return (1);
}

