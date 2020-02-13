/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:47:49 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/02/13 21:28:10 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int			main(int argc, char **argv)
{
	t_form	*form;
	int		i;
	int		j;

	if (argc != 2)
	{
		ft_putstr("error, check your arguments!!!\n");
		return (0);
	}
	form = form_new(argv[1]);
	form->mlx_ptr = mlx_init();
	form->win_ptr = mlx_new_window(form->mlx_ptr, 1000, 1200, "MAP");
	mlx_put_image_to_window(form->mlx_ptr, form->win_ptr, \
								mlx_new_image(form->mlx_ptr,300,400), 30, 120);
	mlx_loop(form->mlx_ptr);
	return (0);
}