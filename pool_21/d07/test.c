/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 01:19:06 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/08 23:14:54 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ex03/ft_concat_params.c"

int		main(int argc, char **argv)
{
//	char str[100];
//	int min;
//	int len;
//	int max;
//	int *array[100];
//	int i;

//	i = 0;
//	scanf("%d %d", &min, &max);
//	len = ft_ultimate_range(array, min, max);
//	max -= min;
	printf("%s", ft_concat_params(argc, argv));
/*	while (--max >= 0)
	{
		printf("%d ", array[0][i]);
		i++;
	}
	printf("%c", '\n');*/
	return (0);
}
