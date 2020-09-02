/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.21-shool.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 10:10:29 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/08/23 10:59:14 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		*lst_map_del(t_list *lst, t_map *m)
{
	t_list	*next;
	int		i;

	i = 0;
	while (lst)
	{
		next = lst->next;
		ft_memdel(&lst->content);
		ft_memdel((void **)&lst);
		lst = next;
	}
	if (m)
	{
		if (m->values)
			while (i < m->height)
			{
				if (m->values + i)
					ft_memdel((void **)(m->values + i));
				i++;
			}
		ft_memdel((void **)&m);
	}
	return (NULL);
}

static t_list	*get_lines(int fd)
{
	int		i;
	t_list	*lst;
	t_list	*temp;
	char	*line;
	int		ret;

	i = -1;
	lst = NULL;
	while ((ret = get_next_line(fd, &line)))
	{
		if (i == -1)
			i = ft_countwords(line, ' ');
		if (i == 0 || (int)ft_countwords(line, ' ') != i ||
			(temp = ft_lstnew(line, ft_strlen(line) + 1)) == NULL)
			return (lst_map_del(lst, NULL));
		ft_strdel(&line);
		ft_lstadd(&lst, temp);
	}
	if (ret == -1)
		return (lst_map_del(lst, NULL));
	ft_lstrev(&lst);
	return (lst);
}

static t_map	*populate_map(t_map *m, t_list *list, int max)
{
	t_list	*temp;
	char	**split;
	int		x;
	int		y;

	temp = list;
	y = 0;
	while (y < m->height)
	{
		x = 0;
		if ((split = ft_strsplit(temp->content, ' ')) == NULL)
			return (lst_map_del(list, m));
		while (x < m->width)
		{
			if ((m->values[y][x] = ft_atoi(split[x])) < 0 ||
					m->values[y][x] > max)
				return (NULL);
			x++;
		}
		ft_splitdel(&split);
		temp = temp->next;
		y++;
	}
	lst_map_del(list, NULL);
	return (m);
}

static t_map	*new_map(int width, int height)
{
	t_map	*m;
	int		i;

	if ((m = (t_map *)ft_memalloc(sizeof(t_map))) == NULL)
		return (NULL);
	m->width = width;
	m->height = height;
	if ((m->values = (int **)ft_memalloc(sizeof(int *) * width)) == NULL)
	{
		ft_memdel((void **)&m);
		return (NULL);
	}
	i = 0;
	while (i < height)
	{
		if ((m->values[i] = (int *)ft_memalloc(sizeof(int) * height)) == NULL)
		{
			while (i > 0)
				ft_memdel((void **)(m->values + --i));
			ft_memdel((void **)&m);
			return (NULL);
		}
		i++;
	}
	return (m);
}

t_map			*read_map(char *file, int max)
{
	t_list	*lst;
	t_map	*map;
	int		fd;

	if ((fd = open(file, O_RDONLY)) == -1 ||
			(lst = get_lines(fd)) == NULL)
		return (NULL);
	map = new_map(ft_countwords((char *)lst->content, ' '), ft_lstcount(lst));
	if (map == NULL)
		return (lst_map_del(lst, NULL));
	if (populate_map(map, lst, max) == NULL ||
			is_full_map(map) || !is_no_holes_map(map))
		return (NULL);
	return (map);
}
