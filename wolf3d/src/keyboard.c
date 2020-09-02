/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.21-shool.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 10:24:48 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/08/23 10:25:12 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		hook_keydown(int key, t_mlx *mlx)
{
	if (key == K_ESC)
		exit(EXIT_SUCCESS);
	if (key == K_LEFT)
		rotate_player(&mlx->player, -ROTATE_SPEED / 180.0f * M_PI);
	if (key == K_RIGHT)
		rotate_player(&mlx->player, ROTATE_SPEED / 180.0f * M_PI);
	if (key == K_UP)
		move_player(&mlx->player, mlx->map, WALK_SPEED);
	if (key == K_DOWN)
		move_player(&mlx->player, mlx->map, -WALK_SPEED);
	render(mlx);
	return (0);
}
