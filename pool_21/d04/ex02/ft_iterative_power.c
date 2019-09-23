/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 10:39:54 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/03 23:09:02 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int result;
	int stage;

	result = nb;
	stage = 1;
	if (power < 0)
		return (0);
	else
	{
		if (stage > power)
			return (1);
		else
		{
			while (stage < power)
			{
				result = result * nb;
				stage++;
			}
			return (result);
		}
	}
}
