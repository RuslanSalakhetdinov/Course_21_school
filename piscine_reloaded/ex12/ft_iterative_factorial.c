/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:07:52 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/03 14:27:29 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int buff;

	if (!nb)
		return (1);
	else if (nb < 0 || nb > 12)
		return (0);
	else
	{
		buff = nb;
		while (--nb > 0)
			buff = nb * buff;
		return (buff);
	}
}
