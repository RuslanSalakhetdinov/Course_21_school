/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.21-shool.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 10:08:46 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/08/23 10:30:39 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	free_textures(t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < TEX_MAP_SIZE)
		delete_image(mlx, mlx->tex[i++]);
}

t_image	*xpm_image(char *xpm, t_mlx *mlx)
{
	t_image		*img;

	if ((img = ft_memalloc(sizeof(t_image))) == NULL)
		return (NULL);
	if ((img->image = mlx_xpm_file_to_image(mlx->mlx, xpm, &img->width,
			&img->height)) == NULL)
		return (delete_image(mlx, img));
	img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->size_line,
		&img->endian);
	img->bpp /= 8;
	img->width = img->size_line / img->bpp;
	img->height = img->size_line / img->bpp;
	return (img);
}

int			load_textures(t_mlx *mlx)
{
	static char	*map[TEX_MAP_SIZE] = { "brick.xpm", "wood.xpm", "metal.xpm",
		"stone.xpm", "grass.xpm", NULL };
	t_image		*img;
	int			i;
	char		*t;

	i = 1;
	while (i < TEX_MAP_SIZE && map[i - 1])
	{
		t = ft_strjoin(("textures/"), map[i - 1]);
		if ((img = xpm_image(t, mlx)) == NULL)
		{
			ft_strdel(&t);
			free_textures(mlx);
			return (1);
		}
		ft_strdel(&t);
		mlx->tex[i] = img;
		i++;
	}
	mlx->max_tex = i - 1;
	mlx->tex[0] = NULL;
	mlx->floor = mlx->tex[2];
	mlx->ceiling = mlx->tex[4];
	return (0);
}
