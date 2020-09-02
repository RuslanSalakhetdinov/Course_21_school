/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.21-shool.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 12:25:42 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/08/23 12:25:44 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int	kill(char *reason)
{
	ft_putendl(reason);
	exit(1);
	return (1);
}

static int	hook_close(t_mlx *mlx)
{
	(void)mlx;
	exit(0);
	return (0);
}

int			main(int argc, char **argv)
{
	t_mlx		*mlx;
	t_map		*map;

	if (argc < 2)
		return (kill("error: not enough arguments\nusage: ./wolf3d [mapfile]"));
	if ((mlx = init()) == NULL)
		return (kill("error: mlx couldn't initialize properly"));
	if (load_textures(mlx))
		return (kill("error: couldn't load textures"));
	if ((map = read_map(argv[1], mlx->max_tex)) == NULL)
		return (kill("error: invalid map file"));
	mlx->map = map;
	init_player(&mlx->player, mlx->map);
	render(mlx);
	mlx_hook(mlx->window, 2, 0, hook_keydown, mlx);
	mlx_hook(mlx->window, 17, 0, hook_close, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
