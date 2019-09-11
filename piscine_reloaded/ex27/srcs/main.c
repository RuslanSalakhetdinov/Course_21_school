/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:33:24 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/04 16:50:09 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			main(int ac, char **av)
{
	int		fd;
	char	buf;

	if (ac < 2)
	{
		ft_putstr("File name missing.\n");
		return (-42);
	}
	if (ac > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (-42);
	}
	fd = open(av[1], O_RDONLY);
	while (read(fd, &buf, 1))
		ft_putchar(buf);
	close(fd);
	return (0);
}
