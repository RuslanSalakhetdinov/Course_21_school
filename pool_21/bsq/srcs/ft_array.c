/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knarwhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 10:43:12 by knarwhal          #+#    #+#             */
/*   Updated: 2019/08/22 11:01:31 by knarwhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	write2zero(int **zero, int **params, int **arr)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	y = -1;
	while (++y < (*params)[0])
	{
		x = -1;
		while (++x < (*params)[5])
			if (arr[x][y] == 0)
			{
				zero[0][i] = x;
				zero[1][i] = y;
				i++;
			}
	}
	zero[0][i] = 1;
	zero[1][i] = 1;
}

void	write2arr(int **arr, int **params, int fd)
{
	int			x;
	int			y;
	char		flag;
	char		buf[1];

	flag = 0;
	x = 0;
	y = 0;
	while ((read(fd, buf, 1)))
	{
		if (flag == 1)
		{
			if (*buf == (char)(*params)[1])
				arr[x++][y] = -1;
			if (*buf == (char)(*params)[2])
				arr[x++][y] = 0;
			if (*buf == '\n')
			{
				y++;
				x = 0;
			}
		}
		if (*buf == '\n')
			flag = 1;
	}
}

void	createarr(int **params, int fd, char *av)
{
	int		**arr;
	int		i;
	int		**startarr;
	int		**zero;

	i = 0;
	arr = malloc(sizeof(*arr) * ((*params)[5]));
	while (i < (*params)[5])
		arr[i++] = malloc(sizeof(**arr) * (*params)[0]);
	arr[i] = malloc(sizeof(**arr));
	zero = malloc(sizeof(*zero) * 2);
	zero[0] = malloc(sizeof(**zero) * ((*params)[4] + 1));
	zero[1] = malloc(sizeof(**zero) * ((*params)[4] + 1));
	startarr = arr;
	close(fd);
	fd = open(av, O_RDONLY);
	write2arr(arr, params, fd);
	arr = startarr;
	write2zero(zero, params, startarr);
	ft_bsq_solution(arr, zero, params);
}

void	checkif(char *buf, char *flag, int **params, int *strcount)
{
	if (*buf != (char)(*params)[1] && *buf != (char)(*params)[2] \
			&& *buf != '\n' && (*params)[7] == 0)
		printerror(params);
	else if ((*buf != '\n') && (*flag == 1))
		(*params)[5]++;
	else if ((*buf != '\n') && (*flag == 2))
		(*strcount)++;
	else if ((*buf == '\n') && (*flag == 2))
	{
		if (*strcount != (*params)[5] && (*params)[7] == 0)
			printerror(params);
		*strcount = 0;
		(*params)[6]++;
	}
	if ((*buf == (char)(*params)[2]) && (*flag >= 0))
		(*params)[4]++;
}
