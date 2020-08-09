/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.21-shool.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 06:41:17 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/08/09 03:46:53 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdint.h>
# include <stdlib.h>
# include <pthread.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"
# include "keys.h"

# define WIN_W 800
# define WIN_H 480
# define ZOOM 1.2f
# define THREADS 48
# define UI_CLR 0xFFFFFF

typedef struct		s_rgba
{
	uint8_t		b;
	uint8_t		g;
	uint8_t		r;
	uint8_t		a;
}					t_rgba;

typedef union		u_color
{
	int			value;
	t_rgba		rgba;
}					t_color;

typedef struct		s_mouse
{
	char		is_down;
	int			x;
	int			y;
	int			last_x;
	int			last_y;
}					t_mouse;

typedef struct		s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			size_line;
	int			endian;
}					t_image;

typedef struct		s_complex
{
	double		r;
	double		i;
}					t_complex;

typedef struct		s_viewport
{
	double		min_x;
	double		max_x;
	double		min_y;
	double		max_y;
	double		zoom;
	double		base_x;
	double		base_y;
	long		iter;
	t_complex	mouse;
}					t_viewport;

typedef struct		s_pixel
{
	t_complex	c;
	long		i;
}					t_pixel;

typedef struct		s_palette
{
	uint8_t		count;
	int			cycle;
	int			colors[16];
}					t_palette;

typedef struct s_mlx	t_mlx;

typedef void		(*fn_viewport)(t_viewport *v);

typedef t_pixel		(*fn_pixel)(int x, int y, t_viewport *v, t_mlx *mlx);

typedef struct		s_fractal
{
	char		*name;
	fn_viewport	viewport;
	fn_pixel	pixel;
	int			mouse;
}					t_fractal;

typedef struct		s_thread
{
	int				id;
	t_mlx			*mlx;
}					t_thread;

typedef struct		s_render
{
	pthread_t		threads[THREADS];
	t_thread		args[THREADS];
}					t_render;

struct				s_mlx
{
	void		*mlx;
	void		*window;
	t_fractal	*fractal;
	t_pixel		*data;
	t_image		*image;
	t_mouse		mouse;
	t_viewport	viewport;
	t_palette	*palette;
	t_render	render;
	int			smooth;
	int			mouselock;
};

t_mlx				*mlx_delete(t_mlx *mlx);
t_mlx				*init(t_fractal *f);
void				render(t_mlx *mlx);
void				draw(t_mlx *mlx);
int					hook_mousedown(int button, int x, int y, t_mlx *mlx);
int					hook_mouseup(int button, int x, int y, t_mlx *mlx);
int					hook_mousemove(int x, int y, t_mlx *mlx);
int					hook_keydown(int key, t_mlx *mlx);
int					hook_expose(t_mlx *mlx);
t_image				*delete_image(t_mlx *mlx, t_image *img);
t_image				*new_image(t_mlx *mlx);
void				clear_image(t_image *img);
void				image_set_pixel(t_image *image, int x, int y, int color);
t_fractal			*fractal_match(char *str);
int					get_color(t_pixel p, t_mlx *mlx);
t_palette			*get_palettes(void);
void				zoom(int x, int y, t_viewport *v, double z);
void				fix_viewport(t_viewport *v);
void				reset_viewport(t_mlx *mlx);
t_complex			screen_to_complex(int x, int y, t_viewport *v);
t_pixel				mandelbrot_pixel(int x, int y, t_viewport *v, t_mlx *mlx);
void				mandelbrot_viewport(t_viewport *v);
t_pixel				burningship_pixel(int x, int y, t_viewport *v, t_mlx *mlx);
void				burningship_viewport(t_viewport *v);
t_pixel				julia_pixel(int x, int y, t_viewport *v, t_mlx *mlx);
void				julia_viewport(t_viewport *v);
t_pixel				tricorn_pixel(int x, int y, t_viewport *v, t_mlx *mlx);
void				tricorn_viewport(t_viewport *v);
t_pixel				julia_cube_pixel(int x, int y, t_viewport *v, t_mlx *mlx);
void				julia_cube_viewport(t_viewport *v);
t_fractal			*get_fractals(void);
void				user_interface_texts(t_mlx *mlx);
void				user_interface(t_mlx *mlx);
t_color				clerp(t_color c1, t_color c2, double p);

#endif
