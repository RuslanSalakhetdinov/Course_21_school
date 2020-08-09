/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.21-shool.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 06:30:23 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/08/08 06:30:25 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fix_viewport(t_viewport *v)
{
	double w;
	double h;

	w = v->max_x - v->min_x;
	h = v->max_y - v->min_y;
	if (w / h >= (float)WIN_W / WIN_H)
	{
		v->min_y = -(w * WIN_H / WIN_W / 2);
		v->max_y = w * WIN_H / WIN_W / 2;
	}
	else
	{
		v->min_x = -(h * WIN_W / WIN_H / 2);
		v->max_x = (h * WIN_W / WIN_H / 2);
	}
}

void		reset_viewport(t_mlx *mlx)
{
	mlx->viewport.base_x = 0;
	mlx->viewport.base_y = 0;
	mlx->fractal->viewport(&(mlx->viewport));
	fix_viewport(&mlx->viewport);
	mlx->viewport.iter = 32;
	mlx->viewport.zoom = 1.0f;
}

t_complex	screen_to_complex(int x, int y, t_viewport *v)
{
	t_complex	p;

	p.r = (((double)x / WIN_W) * (v->max_x - v->min_x)) * v->zoom
		+ v->min_x + v->base_x;
	p.i = (((double)y / WIN_H) * (v->max_y - v->min_y)) * v->zoom
		+ v->min_y + v->base_y;
	return (p);
}
