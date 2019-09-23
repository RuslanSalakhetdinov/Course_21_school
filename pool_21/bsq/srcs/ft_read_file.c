/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knarwhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:19:17 by knarwhal          #+#    #+#             */
/*   Updated: 2019/08/22 11:33:24 by knarwhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	printerror(int **params)
{
	if ((*params)[7] == 0)
	{
		write(2, "map error\n", 10);
		(*params)[7] = 1;
	}
}

void	checkparams(int **params, int fd, char *av)
{
	int		strcount;
	char	buf[1];
	char	flag;

	flag = 0;
	strcount = 0;
	(*params)[4] = 0;
	(*params)[5] = 0;
	(*params)[6] = 2;
	while (read(fd, buf, 1) && (*params)[7] != 1)
	{
		checkif(buf, &flag, params, &strcount);
		if ((*buf == '\n') && (flag == 0))
			flag = 1;
		else if ((*buf == '\n') && (flag == 1))
			flag = 2;
	}
	if ((*params)[0] != (*params)[6])
		printerror(params);
	else
		createarr(params, fd, av);
}

void	init_params(char *arr, int fd, char *av)
{
	int		i;
	int		*params;

	i = 0;
	params = (int*)malloc(sizeof(*params) * PSIZE);
	params[7] = 0;
	while (arr[i] != '\0')
	{
		if (arr[i + 1] == '\0')
		{
			params[3] = (int)arr[i];
			params[2] = (int)arr[i - 1];
			params[1] = (int)arr[i - 2];
			if (params[1] == params[2] || params[2] == params[3] \
			|| params[1] == params[3])
				printerror(&params);
			arr[i - 2] = '\0';
		}
		i++;
	}
	params[0] = ft_atoi(&arr, &params);
	checkparams(&params, fd, av);
}

void	read_1st_str(int fd, char *av)
{
	int		ret;
	char	buf[1];
	char	*arr;
	char	*start;

	arr = (char *)malloc(sizeof(char) * 14);
	start = arr;
	while ((ret = read(fd, buf, 1)))
	{
		if (*buf == '\n')
		{
			*arr = '\0';
			break ;
		}
		*arr++ = *buf;
	}
	arr = start;
	init_params(start, fd, av);
}

int		ft_read_file(char *av)
{
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		write(2, "open() error\n\n", 14);
		return (0);
	}
	read_1st_str(fd, av);
	if (close(fd) == -1)
	{
		write(2, "close() error\n\n", 15);
		return (0);
	}
	return (1);
}
