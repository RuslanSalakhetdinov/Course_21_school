/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 16:54:33 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/03 18:02:32 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int marker;
	int dig;

	marker = 1;
	dig = 1;
	if (nb <= 1)
		return (0);
	else
	{
		while (marker > 0 && dig <= 46340 && dig < nb - 1)
		{
			dig++;
			if (nb % dig == 0)
				marker--;
		}
		return (marker);
	}
}

int		ft_find_next_prime(int nb)
{
	int marker;

	marker = 1;
	if (nb < 0)
		return (0);
	else
	{
		while (marker > 0 && nb <= 2147483627)
		{
			if (ft_is_prime(nb) == 1)
				marker--;
			else
				nb++;
		}
		return (nb);
	}
}
