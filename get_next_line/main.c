/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 21:09:53 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/11/27 23:47:46 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int			main(int ac, char **av)
{
	int		fd1;
	char	*line1;

	line1 = NULL;
	ac += 0;
	fd1 = open(av[1], O_RDONLY);
	while ((get_next_line(fd1, &line1) == 1))
	{
		ft_putstr(line1);
		free(line1);
		ft_putchar('\n');
	}
	return (0);
}
