/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.21-shool.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 06:30:18 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/08/08 06:34:25 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_palette	*get_palettes(void)
{
	static t_palette	array[6];

	array[0] =
		(t_palette){4, 20, {0xE278FF, 0x00BFFF, 0x0022FF, 0x8C00FF}};
	array[1] =
		(t_palette){5, 0, {0x7F1637, 0x047878, 0xFFB733, 0xF57336, 0xC22121}};
	array[2] =
		(t_palette){4, 30, {0xC0C0C0, 0xFFFFFF, 0xFF0000, 0x000000}};
	array[3] =
		(t_palette){7, 10, {0xFF0000, 0xFFFF00, 0x00FF00, 0x00FFFF,
			0x0000FF, 0xFF00FF, 0xFF0000}};
	array[4] =
		(t_palette){2, 20, {0x000000, 0xFFFFFF}};
	array[5] = (t_palette){0, 0, {0}};
	return (array);
}
