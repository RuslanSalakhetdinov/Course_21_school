/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:17:34 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/13 21:20:58 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ex01/ft_foreach.c"

void	ft_putnbr(int n)
{
	printf("%d", n);
}

int		main(void)
{
	int tab[9];
	int l;

	l = -1;
	while(++l < 9)
		tab[l] = l;
	ft_foreach(tab, 9, &ft_putnbr);
	return (0);
}
