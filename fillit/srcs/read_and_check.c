/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:32:22 by lgunship          #+#    #+#             */
/*   Updated: 2020/02/25 01:26:54 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			if_while(int fd, int *i, char **file_in_str)
{
	char	*temp;

	while (get_next_line(fd, &temp) == 1)
	{
		if (++(*i) == 5)
		{
			*i = 0;
			if (ft_strlen(temp) != 0)
			{
				ft_memdel((void*)&temp);
				return (0);
			}
		}
		else
		{
			if (ft_strlen(temp) != 4)
			{
				ft_memdel((void*)&temp);
				return (0);
			}
		}
		ft_strcat(*file_in_str, temp);
		ft_memdel((void*)&temp);
	}
	return (1);
}

int			read_blocks_for_check(char **argv)
{
	int		fd;
	int		i;
	int		flag;
	char	*file_in_str;

	flag = 0;
	i = 0;
	if ((fd = open(argv[1], O_RDONLY) < 0))
		return (-42);
	file_in_str = (char *)malloc(sizeof(char) * 26 * 5);
	if (!(if_while(fd, &i, &file_in_str)))
		flag = 1;
	else if (i != 4)
		flag = 1;
	else if (check_simbols(file_in_str) == -1)
		flag = 1;
	close(fd);
	if (flag == 1)
	{
		ft_memdel((void*)&file_in_str);
		return (-42);
	}
	ft_memdel((void*)&file_in_str);
	return (1);
}

int			check_simbols(char *str)
{
	int		len;

	len = ft_strlen(str);
	while (len > 0)
	{
		len--;
		if (str[len] != '#' && str[len] != '.')
		{
			return (-1);
		}
	}
	return (1);
}
