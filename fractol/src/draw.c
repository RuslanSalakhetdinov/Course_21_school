/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.21-shool.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 06:29:26 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/08/09 03:40:53 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		*render_thread(void *m)
{
	t_thread	*t;
	int			x;
	int			y;

	t = (t_thread *)m;
	y = WIN_H / THREADS * t->id;
	while (y < WIN_H / THREADS * (t->id + 1))
	{
		x = 0;
		while (x < WIN_W)
		{
			t->mlx->data[y * WIN_W + x] =
				t->mlx->fractal->pixel(x, y, &t->mlx->viewport, t->mlx);
			x++;
		}
		y++;
	}
	return (NULL);
}

void		render(t_mlx *mlx)
{
	int			i;
	t_render	*r;

	i = 0;
	r = &mlx->render;
	while (i < THREADS)
	{
		r->args[i].id = i;
		r->args[i].mlx = mlx;
		pthread_create(&(r->threads[i]), NULL, render_thread, &(r->args[i]));
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(r->threads[i], NULL);
		i++;
	}
	draw(mlx);
	user_interface_texts(mlx);
}

void		draw(t_mlx *mlx)
{
	int x;
	int y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			image_set_pixel(mlx->image, x, y,
					get_color(mlx->data[y * WIN_W + x], mlx));
			x++;
		}
		y++;
	}
	user_interface(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image->image, 0, 0);
}

void	user_interface(t_mlx *mlx)
{
	int x;
	int y;
	
	y = 4;
	while (++y < 210)
	{
		x = 5;
		while (++x < 190)
			image_set_pixel(mlx->image, x, y, \
				clerp((t_color)0x000000, \
				(t_color)get_color(mlx->data[y * WIN_W + x], mlx), 0.8f).value);
	}
	y = WIN_H - 44;
	while (++y < WIN_H - 6)
	{
		x = 5;
		while (++x < 190)
			image_set_pixel(mlx->image, x, y, \
				clerp((t_color)0x000000, \
				(t_color)get_color(mlx->data[y * WIN_W + x], mlx), 0.8f).value);
	}

}

void	user_interface_texts(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->window, 17, 15, UI_CLR, "Control Keys");
	mlx_string_put(mlx->mlx, mlx->window, 15, 45, UI_CLR, "Move = ^ v < >");
	mlx_string_put(mlx->mlx, mlx->window, 15, 65, UI_CLR, "Iter = Zoom +");
	mlx_string_put(mlx->mlx, mlx->window, 15, 85, UI_CLR, "NUM_/ and NUM_*");
	mlx_string_put(mlx->mlx, mlx->window, 15, 105, UI_CLR, "Zoom = - and +");
	mlx_string_put(mlx->mlx, mlx->window, 15, 125, UI_CLR, "Mouselock = L");
	mlx_string_put(mlx->mlx, mlx->window, 15, 145, UI_CLR, "Color = 1,2,3,4,6");
	mlx_string_put(mlx->mlx, mlx->window, 15, 165, UI_CLR, "Smo/Line = ENTER");
	mlx_string_put(mlx->mlx, mlx->window, 15, 185, UI_CLR, "Reset = NUM_0");
	mlx_string_put(mlx->mlx, mlx->window, 40, WIN_H - 38, UI_CLR, mlx->fractal->name);
}