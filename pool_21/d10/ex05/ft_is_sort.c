/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:34:56 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/13 21:00:07 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int lenth, int (*f) (int, int))
{
	int i;

	if (length <= 1)
		return (1);
	if ((*f)(tab[0], tab[length - 1]) >= 0)
	{
		i = -1;
		while (++i < length - 1)
			if (tab[i] > tab[i + 1])
				return (0);
	}
	else
	{
		i = -1;
		while (++i < length - 1)
			if (tab[i] < tab[i + 1])
				return (0);
	}
	return (1);
}
