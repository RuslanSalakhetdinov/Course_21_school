/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:21:42 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/03 16:50:08 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putchar(char c)
{
	printf("%c", c);
}

#include "ex22/ft_abs.h"


int		main(void)
{
	int a;
//	int b;

	scanf("%d", &a);
	printf("%d", ABS(a));
}
