/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:37:26 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/20 19:37:28 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_eval(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	return (n);
}

void		ft_putnbr(int n)
{
	char	str[10];
	int		i;

	i = 10;
	while (--i >= 0)
	{
		str[i] = '\0';
	}
	i = 0;
	n = ft_eval(n);
	while (n / 10 != 0)
	{
		str[i] += n % 10;
		n /= 10;
		i++;
	}
	ft_putchar(n + '0');
	while (--i >= 0)
	{
		ft_putchar(str[i]);
	}
}
