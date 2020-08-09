/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.21-shool.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 06:30:10 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/08/09 04:05:40 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal	*get_fractals(void)
{
	static t_fractal	array[6];
	
	array[0] = 
		(t_fractal){"mandelbrot", mandelbrot_viewport, mandelbrot_pixel, 0};
	array[1] =
		(t_fractal){"julia", julia_viewport, julia_pixel, 1};
	array[2] =
		(t_fractal){"burningship", burningship_viewport, burningship_pixel, 0};
	array[3] =
		(t_fractal){"tricorn", tricorn_viewport, tricorn_pixel, 0};
	array[4] =
		(t_fractal){"julia_cube", julia_cube_viewport, julia_cube_pixel, 1};
	array[5] =
		(t_fractal){NULL, NULL, NULL, 0};
	return (array);
}

t_fractal	*fractal_match(char *str)
{
	t_fractal	*f;
	int			i;

	f = get_fractals();
	i = 0;
	while (f[i].name != NULL)
	{
		if (ft_strcmp(f[i].name, str) == 0)
			return (&f[i]);
		i++;
	}
	return (&f[i]);
}

int		kill(char *str)
{
	ft_putendl(str);
	return (1);
}

int		main(int argc, char **argv)
{
	t_mlx		*mlx;
	t_fractal	*f;

	if (argc < 2)
		return (kill("usage: ./fractol\
		{julia, mandebrot, tricorn, burning ship, julia_cube}"));
	f = fractal_match(argv[1]);
	if (f->name == NULL)
		return (kill("error: invalid fractal name\
		{julia, mandebrot, tricorn, burning ship, julia_cube}"));
	if ((mlx = init(f)) == NULL)
		return (kill("error: mlx couldn't initialize properly"));
	reset_viewport(mlx);
	render(mlx);
	mlx_key_hook(mlx->window, hook_keydown, mlx);
	mlx_expose_hook(mlx->window, hook_expose, mlx);
	mlx_hook(mlx->window, 4, 1L << 2, hook_mousedown, mlx);
	mlx_hook(mlx->window, 5, 1L << 3, hook_mouseup, mlx);
	mlx_hook(mlx->window, 6, 1L << 6, hook_mousemove, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
