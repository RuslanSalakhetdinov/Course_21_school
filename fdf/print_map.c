/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:36:10 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/02/18 21:02:54 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_map(t_form *form)
{
	int		x;
	int		y;

	y = 0;
	while (y < form->row)
	{
		x = 0;
		while (x < form->col)
		{
			if (x < form->col -1)
				print_img(x, y, x+1, y, form);
			if (y < form->row -1)
				print_img(x, y, x, y+1, form);
			x++;
		}
		y++;
	}
}