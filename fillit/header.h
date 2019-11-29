/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:45:21 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/11/29 15:13:13 by cwheatgr         ###   ########.fr       */
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
		char			**f; //array of figure
		char			type; //name of symbol
		struct s_form	*link; //maybe use some links???
}						t_form;

//place for prototypes of all functions
t_form					*form_new(char **f, char type);

#endif

