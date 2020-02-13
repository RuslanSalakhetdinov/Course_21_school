/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:56:17 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/02/13 18:57:46 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_row(char *file)
{
	int		fd;
	int		row;
	char	*line;

	row = 0;
	fd = open(file, O_RDONLY, 0);
	while (get_next_line(fd, &line))
	{
		row++;
		free(line);
	}
	close(fd);
	return (row);
}

int			count_col(char *line, char symbol)
{
	char	flag;
	int		count;

	flag = '0';
	while (*line)
	{
		if (*line != symbol && flag == '0')
		{
			count++;
			flag = '1';
		}
		if (*line == symbol && flag == '1')
			flag = '0';
		line++;
	}
	return (count);
}

int			get_col(char *file)
{
	int		fd;
	int		col;
	char	*line;

	fd = open(file, O_RDONLY, 0);
	get_next_line(fd, &line);
	col = count_col(line, ' ');
	close(fd);
	return (col);
}

void		get_depth(int *depth_line, char *line)
{
	char	**split;
	int		i;

	split = ft_strsplit(line, ' ');
	i = -1;
	while (split[++i])
	{
		depth_line[i] = ft_atoi(split[i]);
		free(split[i]);

	}
}

t_form		*form_new(char *file)
{
	t_form	*buf;
	int		fd;
	int		i;

	fd = open(file, O_RDONLY, 0);
	if (!(buf = (t_form*)malloc(sizeof(t_form))))
		return (NULL);
	buf->row = get_row(file);
	buf->col = get_col(file);
	buf->depth = (int**)malloc(sizeof(int*) * (buf_row + 1));
	i = -1;
	while (++i <= buf_row + 1)
		buf->depth[i] = (int*)malloc(sizeof(int) * (buf->col +1));
	i = -1;
	while (get_next_lline(fd, &line))
	{
		get_depth(buf->depth[++i], line);
		free(line);
	}
}