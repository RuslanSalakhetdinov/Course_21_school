/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:32:22 by lgunship          #+#    #+#             */
/*   Updated: 2020/02/24 21:02:48 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int			if_while(int fd, int *i, char **file_in_str)
{
	char	*temp;

	while (get_next_line(fd, &temp) == 1)
	{
		(*i)++;
		if(*i == 5)
		{
			*i = 0;
			if(ft_strlen(temp) != 0)
				return (0);
		}
		else
		{
			if(ft_strlen(temp) != 4)
				return (0);
		}
		ft_strcat(*file_in_str, temp);
		free(temp);
	}
	return (1);
}

int			read_blocks_for_check(char **argv)
{
	int		fd;
	int		i;
	char	*file_in_str;

	i = 0;
	file_in_str = (char *)malloc(sizeof(char) * 26 * 5);
	if ((fd = open(argv[1], O_RDONLY) < 0))
		return (0);
	if(!(if_while(fd, &i, &file_in_str)))
		return (0);
	if (i != 4)
		return (0);
	if (check_simbols(file_in_str) == -1)
		return (0);
	close(fd);
	free(file_in_str);
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