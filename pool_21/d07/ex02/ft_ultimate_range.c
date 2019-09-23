/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 03:34:36 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/08 20:00:39 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int *array;
	int len;

	len = 0;
	if (min >= max)
	{
		*range = ((void*)0);
		return (0);
	}
	max -= min;
	array = (int*)malloc(max * sizeof(*array));
	while (--max >= 0)
	{
		array[max] = max + min;
		len++;
	}
	*range = array;
	return (len);
}
