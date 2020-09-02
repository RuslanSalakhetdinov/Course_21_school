/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.21-shool.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 12:25:25 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/08/23 12:25:27 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	image_set_pixel(t_image *image, int x, int y, int color)
{
	if (!(x < 0 || y < 0 || x >= image->width || y >= image->height))
		*(int *)(image->ptr + ((x + y * image->width) * image->bpp)) = color;
}

void	clear_image(t_image *image)
{
	ft_bzero(image->ptr, image->width * image->height * image->bpp);
}

t_color	get_pixel(t_image *image, int x, int y)
{
	if (x < 0 || y < 0 || x >= image->width || y >= image->height)
		return ((t_color)0x0);
	return ((t_color)*(int *)(image->ptr + ((x + y * image->width)
			* image->bpp)));
}

t_image	*delete_image(t_mlx *mlx, t_image *img)
{
	if (img != NULL)
	{
		if (img->image != NULL)
			mlx_destroy_image(mlx->mlx, img->image);
		ft_memdel((void **)&img);
	}
	return (NULL);
}

t_image	*new_image(t_mlx *mlx, int w, int h)
{
	t_image		*img;

	if ((img = ft_memalloc(sizeof(t_image))) == NULL)
		return (NULL);
	if ((img->image = mlx_new_image(mlx->mlx, w, h)) == NULL)
		return (delete_image(mlx, img));
	img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->size_line,
		&img->endian);
	img->bpp /= 8;
	img->width = w;
	img->height = h;
	return (img);
}
