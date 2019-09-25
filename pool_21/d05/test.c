/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 09:54:18 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/06 23:17:57 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <unistd.h>

#include "ft_putchar.c"

#include "ex18/ft_strlcat.c"

int		main(void)
{
	unsigned int n;
	char str1[256];
	char str2[256];
//	char to_find[256] = "\0";
	scanf("%s\n%s\n%d", str1, str2, &n);
	printf("%d\n%s", ft_strlcat(str1, str2, n), str1);
	return (0);
}
