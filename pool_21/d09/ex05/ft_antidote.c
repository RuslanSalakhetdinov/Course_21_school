/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_antidote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 21:36:29 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/08 21:55:27 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *i, int *j)
{
	int buffer;

	buffer = *i;
	*i = *j;
	*j = buffer;
}

int		ft_antidote(int i, int j, int k)
{
	if (i > j)
		ft_swap(&i, &j);
	if (j > k)
		ft_swap(&j, &k);
	if (i > j)
		ft_swap(&i, &j);
	return (j);
}
