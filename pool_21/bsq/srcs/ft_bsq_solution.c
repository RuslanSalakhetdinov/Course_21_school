/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq_solution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 18:25:17 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/22 11:14:12 by knarwhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_print_if(int **arr, int **elem, int **v, int **params)
{
	char c;

	if ((*v)[0] == (*params)[5])
		write(1, "\n", 1);
	else if (arr[(*v)[0]][(*v)[1]] == 0)
	{
		c = '\0' + (*params)[2];
		write(1, &c, 1);
	}
	else if (((*v)[0] >= (*elem)[0] && (*v)[0] < ((*elem)[0] + (*elem)[2])) \
			&& ((*v)[1] >= (*elem)[1] && (*v)[1] < ((*elem)[1] + (*elem)[2])))
	{
		c = '\0' + (*params)[3];
		write(1, &c, 1);
	}
	else
	{
		c = '\0' + (*params)[1];
		write(1, &c, 1);
	}
}

void	ft_print_bsq(int **arr, int **elem, int **v, int **params)
{
	(*v)[1] = -1;
	while (++((*v)[1]) < (*params)[0])
	{
		(*v)[0] = -1;
		while (++((*v)[0]) <= (*params)[5])
		{
			ft_print_if(arr, elem, v, params);
		}
	}
	ft_clean(arr, elem, v, params);
}

int		ft_max(int **params)
{
	if ((*params)[0] > (*params)[5])
		return ((*params)[0]);
	return ((*params)[5]);
}

void	ft_check_bsq_elem(int **arr, int **v, int **params)
{
	int *elem;

	elem = malloc(sizeof(*elem) * 3);
	elem[2] = -1;
	(*v)[1] = -1;
	while (++((*v)[1]) < (*params)[0])
	{
		(*v)[0] = -1;
		while (++((*v)[0]) < (*params)[5])
		{
			if (arr[(*v)[0]][(*v)[1]] > elem[2])
			{
				elem[0] = (*v)[0];
				elem[1] = (*v)[1];
				elem[2] = arr[(*v)[0]][(*v)[1]];
			}
		}
	}
	if ((*params)[4] == 0)
	{
		elem[0] = 0;
		elem[1] = 0;
		elem[2] = ft_max(params);
	}
	ft_print_bsq(arr, &elem, v, params);
}
