/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itrative_factorial.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 23:05:44 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/04 15:57:30 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int result;

	result = 1;
	if (nb > 0 && nb < 13)
	{
		while (nb >= 1)
		{
			result = result * nb;
			nb--;
		}
		return (result);
	}
	else
	{
		if (nb == 0)
			return (1);
		else
			return (0);
	}
}
