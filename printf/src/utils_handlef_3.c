/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_handlef_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.21-shool.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 13:40:32 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/08/16 13:40:35 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_helper_f_nan(t_prf *prf)
{
	prf->precision = 0;
	prf->precision_flag = 1;
	prf->zero_flag = 0;
	prf->hash_flag = 0;
}

void	flag_manager_f(long double f, t_prf *prf)
{
	if (is_nan(f) || is_inf(f))
	{
		flag_helper_f_nan(prf);
		if (is_nan(f))
		{
			prf->plus_flag = 0;
			prf->is_nan = 1;
		}
		else
		{
			prf->is_inf = 1;
			if (f == -(1.0 / 0))
				prf->is_neg = 1;
		}
	}
	if (prf->minus_flag)
		prf->zero_flag = 0;
	if (prf->plus_flag)
		prf->space_flag = 0;
	if (!prf->precision_flag)
	{
		prf->precision_flag = 1;
		prf->precision = 6;
	}
}

void	free_helper_f(t_prf *prf, char *big_s, char *little_s)
{
	if (!prf->is_inf && !prf->is_nan)
	{
		free(big_s);
		free(little_s);
	}
}
