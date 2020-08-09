/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.21-shool.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 06:30:05 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/08/09 03:34:20 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		draw_hooks(int key, t_mlx *mlx)
{
	int		flag;

	flag = 0;
	if (key >= K_DIGIT_1 && key <= K_DIGIT_1 + 4)
		mlx->palette = &get_palettes()[key - K_DIGIT_1];
	else if (key == K_NUM_ENTER)
		mlx->smooth = 1 - mlx->smooth;
	else
		flag = 1;
	if (!flag)
		render(mlx);
	return (flag);
}

void	move(int key, t_mlx *mlx)
{
	double w;
	double h;

	w = (mlx->viewport.max_x - mlx->viewport.min_x) * mlx->viewport.zoom;
	h = (mlx->viewport.max_y - mlx->viewport.min_y) * mlx->viewport.zoom;
	if (key == K_UP)
		mlx->viewport.base_y -= h * 0.05f;
	if (key == K_DOWN)
		mlx->viewport.base_y += h * 0.05f;
	if (key == K_LEFT)
		mlx->viewport.base_x -= w * 0.05f;
	if (key == K_RIGHT)
		mlx->viewport.base_x += w * 0.05f;
	if (key == K_L)
		mlx->mouselock = 1 - mlx->mouselock;
}

int		hook_keydown(int key, t_mlx *mlx)
{
	if (key == K_ESC)
		exit(EXIT_SUCCESS);
	if (key == K_NUM_0)
		reset_viewport(mlx);
	if (key == K_NUM_MULT)
		mlx->viewport.iter *= 2;
	if (key == K_NUM_DIV)
		if (mlx->viewport.iter / 2 >= 2)
			mlx->viewport.iter /= 2;
	if (key == K_NUM_PLUS)
		zoom(WIN_W / 2, WIN_H / 2, &mlx->viewport, 1 / ZOOM);
	if (key == K_NUM_MINUS)
		zoom(WIN_W / 2, WIN_H / 2, &mlx->viewport, ZOOM);
	move(key, mlx);
	if (draw_hooks(key, mlx))
		render(mlx);
	return (0);
}

int		hook_expose(t_mlx *mlx)
{
	render(mlx);
	return (0);
}