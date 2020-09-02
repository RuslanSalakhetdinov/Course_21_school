/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.21-shool.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 12:26:16 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/08/23 12:26:19 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	place_player(t_player *player, t_map *map)
{
	int	x;
	int	y;
	int	f;

	y = 0;
	f = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (!(f = map_block(map, x, y)))
				break ;
			x++;
		}
		if (!f)
			break ;
		y++;
	}
	player->x = x + 0.5f;
	player->y = y + 0.5f;
}

void		init_player(t_player *player, t_map *map)
{
	place_player(player, map);
	player->d.x = 1.0f;
	player->d.y = 0.0f;
	player->p.x = 0.0f;
	player->p.y = 2.0f / 3.0f;
}

static void	rotate(t_vector *v, float angle)
{
	float x;
	float c;
	float s;

	x = v->x;
	c = cos(angle);
	s = sin(angle);
	v->x = v->x * c - v->y * s;
	v->y = x * s + v->y * c;
}

void		rotate_player(t_player *player, float angle)
{
	rotate(&player->d, angle);
	rotate(&player->p, angle);
}

void		move_player(t_player *p, t_map *m, float distance)
{
	if (!map_block(m, p->x + distance * p->d.x, p->y))
		p->x += distance * p->d.x;
	if (!map_block(m, p->x, p->y + distance * p->d.y))
		p->y += distance * p->d.y;
}
