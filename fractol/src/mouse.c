/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.21-shool.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 06:30:14 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/08/09 03:34:04 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		hook_mousedown(int button, int x, int y, t_mlx *mlx)
{
	if (button == 4)
	{
		zoom(x, y, &mlx->viewport, 1 / ZOOM);
		render(mlx);
	}
	else if (button == 5)
	{
		zoom(x, y, &mlx->viewport, ZOOM);
		render(mlx);
	}
	if (y < 0)
		return (0);
	mlx->mouse.is_down |= 1 << button;
	return (0);
}

int		hook_mouseup(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	mlx->mouse.is_down &= ~(1 << button);
	return (0);
}

int		hook_mousemove(int x, int y, t_mlx *mlx)
{
	double w;
	double h;

	mlx->mouse.last_x = mlx->mouse.x;
	mlx->mouse.last_y = mlx->mouse.y;
	mlx->mouse.x = x;
	mlx->mouse.y = y;
	if (!mlx->mouselock)
		mlx->viewport.mouse = screen_to_complex(x, y, &mlx->viewport);
	if (mlx->mouse.is_down & (1 << 1))
	{
		w = (mlx->viewport.max_x - mlx->viewport.min_x) * mlx->viewport.zoom;
		h = (mlx->viewport.max_y - mlx->viewport.min_y) * mlx->viewport.zoom;
		mlx->viewport.base_x += (double)(mlx->mouse.last_x - mlx->mouse.x)
			/ WIN_W * w;
		mlx->viewport.base_y += (double)(mlx->mouse.last_y - mlx->mouse.y)
			/ WIN_H * h;
	}
	if (mlx->mouse.is_down || (mlx->fractal->mouse && !mlx->mouselock))
		render(mlx);
	return (0);
}
