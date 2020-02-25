/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_it_tetra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:11:32 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/02/25 01:26:04 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		is_it_tetra(char *buf)
{
	int	i;
	int	count;
	int	num;

	i = 0;
	count = 0;
	num = 0;
	while (i <= 18)
	{
		if (buf[i] == '#')
		{
			num++;
			if (i - 1 >= 0 && buf[i - 1] == '#')
				count++;
			if (i - 5 >= 0 && buf[i - 5] == '#')
				count++;
			if (i + 1 <= 18 && buf[i + 1] == '#')
				count++;
			if (i + 5 <= 18 && buf[i + 5] == '#')
				count++;
		}
		i++;
	}
	return ((count == 6 || count == 8) && num == 4);
}
