/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 14:23:10 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/03 23:22:36 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_fibonacci(int index)
{
	if (index < 0 || index > 46)
		return (-1);
	else
	{
		if (index == 0)
			return (0);
		else
		{
			if (index == 1)
				return (1);
			else
				return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
		}
	}
}
