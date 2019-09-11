/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:32:19 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/05 16:28:22 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *arr;

	if (min >= max)
		return (0);
	max -= min;
	arr = malloc(sizeof(*arr) * max);
	if (!arr)
		return (0);
	while (--max >= 0)
		arr[max] = min + max;
	return (arr);
}
