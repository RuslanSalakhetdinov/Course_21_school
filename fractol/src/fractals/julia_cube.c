/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_cube.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.21-shool.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 04:06:18 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/08/09 04:06:21 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_pixel		julia_cube_pixel(int x, int y, t_viewport *v, t_mlx *mlx)
{
	t_complex	z;
	t_complex	c;
	t_complex	temp;
	int			i;

	(void)mlx;
	z = screen_to_complex(x, y, v);
	c = v->mouse;
	i = 0;
	while (z.r * z.r + z.i * z.i < 100 && i < v->iter)
	{
		temp.r = z.r * z.r * z.r - 3 * z.i * z.i * z.r + c.r;
		temp.i = 3 * z.r * z.r * z.i - z.i * z.i * z.i + c.i;
		if (z.r == temp.r && z.i == temp.i)
		{
			i = v->iter;
			break ;
		}
		z.r = temp.r;
		z.i = temp.i;
		i++;
	}
	return ((t_pixel){.c = z, .i = i});
}

void		julia_cube_viewport(t_viewport *v)
{
	v->min_x = -2.0f;
	v->max_x = 2.0f;
	v->min_y = -2.0f;
	v->max_y = 2.0f;
}