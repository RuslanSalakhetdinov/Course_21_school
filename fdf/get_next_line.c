/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:54:01 by lgunship          #+#    #+#             */
/*   Updated: 2020/02/13 20:11:10 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				check_line(const int fd, char **line, \
							char **str, ssize_t read_bytes)
{
	int			length;
	char		*temp;

	length = 0;
	while ((str[fd][length] != '\n') && (str[fd][length] != '\0'))
		length++;
	if (str[fd][length] == '\n')
	{
		*line = ft_strsub(str[fd], 0, length);
		temp  = ft_strdup(str[fd] + length + 1);
		free(str[fd]);
		str[fd] = temp;
		if (str[fd] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][length] == '\0')
	{
		if (read_bytes == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	ssize_t		read_bytes;
	char		buffer[BUFF_SIZE + 1];
	static char	*str[255];
	char *		temp;

	if ((fd < 0) || (line == NULL))
		return (-1);
	while (((read_bytes = read(fd, buffer, BUFF_SIZE)) > 0))
	{
		buffer[read_bytes] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(1);
		temp = ft_strjoin(str[fd], buffer);
		free(str[fd]);
		str[fd] = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (read_bytes < 0)
		return (-1);
	else if (read_bytes == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	return (check_line(fd, line, str, read_bytes));
}
