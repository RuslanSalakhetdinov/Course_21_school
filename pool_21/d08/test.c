/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:23:35 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/09 14:34:15 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ex00/ft_split_whitespaces.c"

int 	main(void)
{
	char *str;

	scanf("%s", str);
	printf("%s", ft_split_whitespaces(str));
	return (0);
}
