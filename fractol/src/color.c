/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.21-shool.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 06:29:53 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/08/08 17:10:31 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color		clerp(t_color c1, t_color c2, double p)
{
	t_color c;

	if (c1.value == c2.value)
		return (c1);
	c.rgba.r = (char)ft_lerpi((int)c1.rgba.r, (int)c2.rgba.r, p);
	c.rgba.g = (char)ft_lerpi((int)c1.rgba.g, (int)c2.rgba.g, p);
	c.rgba.b = (char)ft_lerpi((int)c1.rgba.b, (int)c2.rgba.b, p);
	c.rgba.a = (char)0x00;
	return (c);
}

t_color		linear_color(double i, int iter, t_palette *p)
{
	double		index;
	double		adjust;
	int			c;

	if (p->cycle)
		index = fmod(i, p->cycle - 1) / (p->cycle - 1);
	else
		index = i / iter;
	c = p->count - 1;
	adjust = fmod(index, 1.0f / c) * c;
	return (clerp((t_color)(p->colors[(int)(index * c) + 1]),
		(t_color)(p->colors[(int)(index * c)]),
		(int)(adjust + 1) - adjust));
}

t_color		smooth_color(t_pixel p, int iter, t_palette *palette)
{
	double i;
	double z;
	double n;

	z = log(p.c.r * p.c.r + p.c.i * p.c.i) / 2.0f;
	n = log(z / log(2)) / log(2);
	i = p.i + 1 - n;
	if (i < 0)
		i = 0;
	return (linear_color(i, iter, palette));
}

int			get_color(t_pixel p, t_mlx *mlx)
{
	if (p.i >= mlx->viewport.iter)
		return (0x000000);
	if (mlx->smooth)
		return (smooth_color(p, mlx->viewport.iter, mlx->palette).value);
	return (linear_color((double)p.i, mlx->viewport.iter, mlx->palette).value);
}
