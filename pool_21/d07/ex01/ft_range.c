/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 01:26:09 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/08 23:40:02 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *array;

	max -= min;
	array = malloc(max * sizeof(*array));
	if (!array)
		return (0);
	while (--max >= 0)
		array[max] = max + min;
	return (array);
}
