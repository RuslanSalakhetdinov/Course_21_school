/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knarwhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:25:07 by knarwhal          #+#    #+#             */
/*   Updated: 2019/08/22 11:35:16 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		main(int ac, char **av)
{
	int		ac_count;

	ac_count = 1;
	if (ac == 1)
		return (0);
	while (ac_count < ac)
	{
		if (ft_read_file(av[ac_count++]) == 0)
			continue ;
		if (ac_count < ac)
			write(1, "\n", 1);
	}
	return (0);
}
