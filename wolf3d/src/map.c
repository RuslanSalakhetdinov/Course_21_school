/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.21-shool.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 12:25:50 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/08/23 12:25:52 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		map_block(t_map *m, int x, int y)
{
	if (x < 0 || y < 0 || x > m->width - 1 || y > m->height - 1)
		return (0);
	return (m->values[y][x]);
}

int		is_full_map(t_map *m)
{
	int x;
	int y;

	y = 0;
	while (y < m->height)
	{
		x = 0;
		while (x < m->width)
		{
			if (map_block(m, x, y) == 0)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int		is_no_holes_map(t_map *m)
{
	int x;
	int y;

	y = 0;
	while (y < m->height)
	{
		x = 0;
		while (x < m->width)
		{
			if ((x == 0 || y == 0 || x == m->width - 1 || y == m->height) &&
					map_block(m, x, y) == 0)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
