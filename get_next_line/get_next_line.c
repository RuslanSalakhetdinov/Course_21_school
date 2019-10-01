/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 20:15:41 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/10/01 22:52:45 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					get_next_line(const int fd, char **line)
{
	static t_fdlt	*main;
	t_fdlt			*temp;
	char			buf[BUF_SIZE];
	int				ret;

	if (!(len = read(fd, buf, BUF_SIZE)))
		return (0);
	
}
