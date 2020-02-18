	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:36:17 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/02/13 22:12:45 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include <math.h>
//delete then
# include <stdio.h>

/*
** clang *.c libft/libft.a -L/usr/local/lib/ -I/usr/local/include -framework OpenGL -framework AppKit -lmlx
*/

typedef struct			s_form
{
		int				**depth;
		int				row;
		int				col;
		int				zoom;
		int				color;
		int				shift;
		void			*mlx_ptr;
		void			*win_ptr;
}						t_form;

t_form					*form_new(char *file);
void					print_img(double x, double y, double x1, double y1, t_form *form);
void					print_map(t_form *form);
void					isometric(double *x, double *y, int z);




#endif