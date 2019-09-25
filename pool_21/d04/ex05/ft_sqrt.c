/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 14:58:35 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/03 15:28:08 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int dig;
	int marker;

	dig = -1;
	marker = -1;
	if (nb < 0)
		return (0);
	else
	{
		while (nb > dig * dig && dig <= 46340)
		{
			dig++;
			if (dig * dig == nb)
				marker++;
		}
		if (marker == 0)
			return (dig);
		else
			return (0);
	}
}
