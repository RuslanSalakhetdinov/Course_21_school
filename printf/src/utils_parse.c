/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.21-shool.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 13:40:40 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/08/16 13:40:43 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_star_width(t_prf *prf, va_list ap, int star_flag)
{
	int garbage;

	if (!prf->width || !star_flag)
	{
		prf->width = va_arg(ap, int);
		if (prf->width < 0)
		{
			prf->width = -prf->width;
			prf->minus_flag = 1;
		}
		return (1);
	}
	else
	{
		garbage = va_arg(ap, int);
		return (star_flag);
	}
}
