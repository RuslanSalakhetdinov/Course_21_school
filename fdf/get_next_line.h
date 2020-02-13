/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:54:11 by lgunship          #+#    #+#             */
/*   Updated: 2020/02/13 20:11:08 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include "../libft/libft.h"

#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE	64
int		check_line(const int fd, char **line, char **str, ssize_t read_bytes);
int		get_next_line(const int fd, char **line);

#endif
