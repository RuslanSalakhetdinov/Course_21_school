/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 12:50:06 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/03 23:11:45 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else
	{
		if (1 > power)
			return (1);
		else
			return (nb * ft_recursive_power(nb, power - 1));
	}
}

int		main(void)
{
	int n;
	int k;

	scanf("%d %d", &n, &k);
	printf("%d", ft_recursive_power(n, k));
	return (0);
}
