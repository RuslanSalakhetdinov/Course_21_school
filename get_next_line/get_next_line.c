/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 20:15:41 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/11/27 19:09:14 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fdlt				*fdltnew(int fd)
{
	t_fdlt			*new;

	if (!(new = (t_fdlt*)malloc(sizeof(*new))))
		return (NULL);
	new->str = ft_strnew(0);
	new->fd = fd;
	new->next = NULL;
	return (new);
}

t_fdlt				*search_list_fd(t_fdlt **main, int fd)
{
	t_fdlt			*temp;
	t_fdlt			*buf;

	if (fd < 0)
		return (NULL);
	if (!(*main))
	{
		temp = fdltnew(fd);
		(*main) = temp;
	}
	else
	{
		buf = (*main);
		while (buf->fd != fd && buf->next)
			buf = buf->next;
		if (buf->fd == fd)
			temp = buf;
		else
		{
			temp = fdltnew(fd);
			buf->next = temp;
		}
	}
	return (temp);
}

int					make_line(char **str, char **line)
{
	int				len;
	char			*buf;

	len = 0;
	while ((*str)[len] != '\n' && (*str)[len] != '\0')
		len++;
	if ((*str)[len] == '\n')
	{
		*line = ft_strsub(*str, 0, len);
		buf = ft_strdup(&((*str)[len + 1]));
		free(*str);
		*str = buf;
	}
	else
	{
		*line = ft_strdup(*str);
		free(*str);
		str = ft_strnew(0);
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_fdlt	*main;
	t_fdlt			*temp;
	char			buf[BUF_SIZE + 1];
	int				ret;
	char			*temp_str;

	if (fd < 0 || !line || !(temp = search_list_fdlt(&main, fd)))
		return (-1);
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
		{
			buf[ret] = '\0';
			temp_str = ft_strjoin(temp->str, buf);
			free(temp->str);
			temp->str = temp_str;
		}
		if (ft_strchr(temp->str, '\n'))
			break ;
	if (ret < 0)
		return (-1);
	else if (ret == 0 && !(temp->str))
		return (0);
	else
		return (make_line(&(temp->str), line));
}
