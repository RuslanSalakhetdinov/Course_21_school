/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:46:45 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/08 21:54:17 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ex05/ft_antidote.c"

int		main(void)
{
//	int hour;
//	char str[256];
	int i;
	int j;
	int k;


	scanf("%d %d %d", &i, &j, &k);
	printf("%d", ft_antidote(i, j, k));
	return (0);
}
