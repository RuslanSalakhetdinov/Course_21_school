/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 17:52:54 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/17 17:21:09 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

int		ft_if(int argc, char **argv)
{
	if (ft_atoi(argv[3]) == 0)
	{
		if (ft_valid(argc, argv) == 2)
		{
			write(1, "Stop : division by zero\n", 24);
			return (0);
		}
		if (ft_valid(argc, argv) == 3)
		{
			write(1, "Stop : modulo by zero\n", 22);
			return (0);
		}
	}
	return (1);
}

int		main(int argc, char **argv)
{
	long long nbr;
	long long (*f_arr[5])(int, int);

	if (ft_valid(argc, argv) == -1)
		ft_putnbr(0);
	f_arr[0] = &ft_add;
	f_arr[1] = &ft_sub;
	f_arr[2] = &ft_div;
	f_arr[3] = &ft_mod;
	f_arr[4] = &ft_mul;
	if (ft_if(argc, argv) == 0)
		return (0);
	if (ft_atoi(argv[1]) == -2147483648 && ft_atoi(argv[3]) == -2147483648)
	{
		ft_putnbr(0);
		return (0);
	}
	nbr = f_arr[ft_valid(argc, argv)](ft_atoi(argv[1]), ft_atoi(argv[3]));
	if (nbr >= -2147483648 && nbr <= 2147483647)
		ft_putnbr(nbr);
	else
		ft_putnbr(0);
	return (0);
}
