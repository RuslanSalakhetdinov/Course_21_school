/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.21-shool.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 06:30:35 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/08/08 06:32:09 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		zoom(int x, int y, t_viewport *v, double z)
{
	double w;
	double h;
	double nw;
	double nh;

	w = (v->max_x - v->min_x) * (v->zoom);
	h = (v->max_y - v->min_y) * (v->zoom);
	nw = (v->max_x - v->min_x) * (v->zoom * z);
	nh = (v->max_y - v->min_y) * (v->zoom * z);
	v->zoom *= z;
	v->base_x -= ((double)x / WIN_W) * (nw - w);
	v->base_y -= ((double)y / WIN_H) * (nh - h);
		if (z > 1 && v->iter > 32)
			v->iter -= 1;
		else if (z < 1 && v->iter < 200)
			v->iter += 1;
}
