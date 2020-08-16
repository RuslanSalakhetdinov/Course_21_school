/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.21-shool.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 13:40:02 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/08/16 13:40:04 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int			signed_handle_mod(t_prf *prf, va_list ap)
{
	long long int n;

	if (prf->modifier == LL)
		n = va_arg(ap, long long int);
	else if (prf->modifier == L)
		n = va_arg(ap, long int);
	else if (prf->modifier == H)
		n = (short int)va_arg(ap, int);
	else if (prf->modifier == HH)
		n = (char)va_arg(ap, int);
	else
		n = (int)va_arg(ap, int);
	return (n);
}

unsigned long long int	unsigned_handle_mod(t_prf *prf, va_list ap)
{
	unsigned long long int n;

	if (prf->modifier == LL)
		n = va_arg(ap, unsigned long long int);
	else if (prf->modifier == L)
		n = va_arg(ap, unsigned long int);
	else if (prf->modifier == H)
		n = (unsigned short int)va_arg(ap, unsigned int);
	else if (prf->modifier == HH)
		n = (unsigned char)va_arg(ap, unsigned int);
	else
		n = (unsigned int)va_arg(ap, unsigned int);
	return (n);
}

char					set_sign(long long int n, t_prf *prf)
{
	char sign;

	sign = prf->space_flag ? ' ' : '+';
	if (n < 0)
	{
		sign = '-';
		prf->is_neg = 1;
	}
	return (sign);
}

void					flag_manager(t_prf *prf)
{
	if (prf->precision_flag || prf->minus_flag)
		prf->zero_flag = 0;
	if (prf->plus_flag)
		prf->space_flag = 0;
}

void					pad_prf(t_prf *prf, int len, int b_len, int seg)
{
	if (!prf->zero_flag && !prf->minus_flag && prf->width >
		b_len && seg == START)
		write_padding(prf->width - b_len, ' ');
	else if (!prf->zero_flag && prf->minus_flag && prf->width >
		b_len && seg == END)
		write_padding(prf->width - b_len, ' ');
	else if (seg == ZEROS)
	{
		if (prf->precision_flag)
			write_padding(prf->precision > len ? prf->precision - len : 0, '0');
		else if (prf->zero_flag && prf->width)
			write_padding(prf->width > b_len ? prf->width - b_len : 0, '0');
	}
}
