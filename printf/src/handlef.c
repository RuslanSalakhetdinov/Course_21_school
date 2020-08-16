/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlef.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.21-shool.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 13:37:25 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/08/16 13:38:49 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pad_prf_f(int len, t_prf *prf, int seg)
{
	if (!prf->zero_flag && !prf->minus_flag && prf->width >
		len && seg == START)
		write_padding(prf->width - len, ' ');
	else if (!prf->zero_flag && prf->minus_flag && prf->width >
		len && seg == END)
		write_padding(prf->width - len, ' ');
	else if (seg == ZEROS)
	{
		if (prf->zero_flag && prf->width)
			write_padding(prf->width > len ? prf->width - len : 0, '0');
	}
}

int		prf_len_f(char *big_s, t_prf *prf)
{
	int len;

	if (prf->is_inf || prf->is_nan)
		len = 3;
	else
		len = ft_strlen(big_s) + prf->precision;
	if (prf->precision > 0 || prf->hash_flag)
		len += 1;
	if (prf->space_flag || prf->plus_flag)
		len += 1;
	return (len);
}

char	set_sign_f(long double f, t_prf *prf)
{
	char sign;

	sign = prf->space_flag ? ' ' : '+';
	if (f < 0)
	{
		sign = '-';
		prf->is_neg = 1;
	}
	return (sign);
}

int		write_f(t_prf *prf, char sign, char *big_s, char *little_s)
{
	int len;

	len = prf_len_f(big_s, prf);
	pad_prf_f(len, prf, START);
	if (prf->space_flag || prf->plus_flag || prf->is_neg)
	{
		write(1, &sign, 1);
		len++;
	}
	pad_prf_f(len, prf, ZEROS);
	write(1, big_s, ft_strlen(big_s));
	if (prf->precision || prf->hash_flag)
		write(1, ".", 1);
	write(1, little_s, ft_strlen(little_s));
	pad_prf_f(len, prf, END);
	return (len);
}

int		handle_f(t_prf *prf, va_list ap)
{
	long double	f;
	char		*little_s;
	char		*big_s;
	char		sign;
	int			len;

	f = float_handle_mod(prf, ap);
	flag_manager_f(f, prf);
	sign = set_sign_f(f, prf);
	if (!prf->is_inf && !prf->is_nan)
	{
		f = ft_round(f, prf);
		big_s = big_f(f);
		little_s = little_f(f, prf->precision, big_s);
	}
	else
	{
		big_s = prf->is_inf ? "inf" : "nan";
		little_s = "";
	}
	len = write_f(prf, sign, big_s, little_s);
	free_helper_f(prf, big_s, little_s);
	return (MAX(prf->width, len));
}
