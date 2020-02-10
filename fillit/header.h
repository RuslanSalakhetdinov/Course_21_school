/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:45:21 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/02/10 10:04:44 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <sys/types,h>
# include <sys?stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct			s_form //I think, my type is a good idea, kek
{
		int				pos[4][2]; //array of figure
		char			symbol; //name of symbol
		int				x_base; //zero position X coordinate
		int				y_base;//zero position Y coordinate
		struct s_form	*next;
}						t_form;

typedef struct			s_board
{
		char			**map; //array of coordinates
		int				size;
}						t_board;
//place for prototypes of all functions
t_form					*form_new(char **f, char type);
void					form_del(t_form **main);

#endif

