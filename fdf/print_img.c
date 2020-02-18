/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:14:15 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/02/18 22:22:00 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		isometric(double *x, double *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - (double)z;
}

void		print_img(double x, double y, double x1, double y1, t_form *form)
{
	double	x_size; 
	double	y_size;
	double	max;
	int		z;
	int		z1;

	z = form->depth[(int)y][(int)x];
	z1 = form->depth[(int)y1][(int)x1];
	form->color = (z || z1) ? 0xff0000 : 0xffffff;
	x *= form->zoom;
	x1 *= form->zoom;
	y *= form->zoom;
	y1 *= form->zoom;
	//printf("x = %11f, y = %11f, x1 = %11f, y1 = %11f, z = %3d, z1 = %3d\n", x, y, x1, y1, z, z1);
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	//printf("x = %11f, y = %11f, x1 = %11f, y1 = %11f, z = %3d, z1 = %3d\n", x, y, x1, y1, z, z1);
	x += form->shift;
	x1 += form->shift;
	y += form->shift;
	y1 += form->shift;
	x_size = x1 - x;
	y_size = y1 - y;
	max = fmax(fabs(x_size), fabs(y_size));
	x_size /= max;
	y_size /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(form->mlx_ptr, form->win_ptr, x, y, form->color);
		x += x_size;
		y += y_size;
		if (x > 1920 || y > 1080 || x < 0 || y < 0)
			break ;
	}
}