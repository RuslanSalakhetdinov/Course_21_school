/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:38:06 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/14 14:57:20 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f) (int))
{
	int i;
	int *arr;

	i = -1;
	arr = (int*)malloc(length * sizeof(*arr));
	while (++i < length)
		arr[i] = (*f)(tab[i]);
	return (arr);
}
