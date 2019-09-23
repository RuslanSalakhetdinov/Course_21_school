/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knarwhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 11:14:35 by knarwhal          #+#    #+#             */
/*   Updated: 2019/08/22 11:20:33 by knarwhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_bsq_if(int **arr, int **zero, int **params, int **v)
{
	while (++((*v)[3]) < (*params)[4] && (*params)[4] != 0)
	{
		if ((((*v)[1] + (*v)[2]) >= zero[1][(*v)[3]] && \
					(*v)[1] <= zero[1][(*v)[3]] \
					&& ((*v)[0] + (*v)[2]) == zero[0][(*v)[3]]) || \
				(((*v)[0] + (*v)[2]) >= zero[0][(*v)[3]] && \
				(*v)[0] <= zero[0][(*v)[3]] \
				&& ((*v)[1] + (*v)[2]) == zero[1][(*v)[3]]) || \
				(*v)[1] + (*v)[2] == (*params)[0] || \
				(*v)[0] + (*v)[2] == (*params)[5])
		{
			arr[(*v)[0]][(*v)[1]] = (*v)[2];
			((*v)[4])++;
			break ;
		}
	}
}

void	ft_bsq_solution(int **arr, int **zero, int **params)
{
	int *v;

	v = malloc(sizeof(*v) * 5);
	v[1] = -1;
	while (++v[1] < (*params)[0])
	{
		v[0] = -1;
		while (++v[0] < (*params)[5])
		{
			if (arr[v[0]][v[1]] == -1)
			{
				v[2] = 1;
				v[4] = 0;
				while (v[4] == 0)
				{
					v[3] = -1;
					ft_bsq_if(arr, zero, params, &v);
					v[2]++;
				}
			}
		}
	}
	ft_check_bsq_elem(arr, &v, params);
	ft_delete_zero(zero);
}

void	ft_clean(int **arr, int **elem, int **v, int **params)
{
	int i;

	i = -1;
	while (++i < (*params)[5])
		free(arr[i]);
	free(arr);
	free((*elem));
	free((*v));
	free((*params));
}

void	ft_delete_zero(int **zero)
{
	free(zero[0]);
	free(zero[1]);
	free(zero);
}
