/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 10:09:27 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/13 20:25:44 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

int		ft_eval(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	return (nb);
}

void	ft_putnbr(int nb)
{
	char	str[10];
	int		n;

	n = 10;
	while (--n >= 0)
	{
		str[n] = '0';
	}
	n++;
	nb = ft_eval(nb);
	while (nb / 10 != 0)
	{
		str[n] += nb % 10;
		nb /= 10;
		n++;
	}
	ft_putchar(nb + '0');
	while (--n >= 0)
	{
		ft_putchar(str[n]);
	}
}
