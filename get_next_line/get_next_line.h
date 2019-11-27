/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 20:16:59 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/11/27 21:35:16 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft/libft.h"

typedef	struct		s_fdlt
{
	char			*str;
	int				fd;
	struct s_fdlt	*next;
}					t_fdlt;

t_fdlt				*fdltnew(int fd);
t_fdlt				*find_list_fd(t_fdlt **main, int fd);
int					make_line(char **str, char **line);
int					get_next_line(const int fd, char **line);

#endif
