/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 15:29:17 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/03 16:19:21 by cwheatgr         ###   ########.fr       */
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
