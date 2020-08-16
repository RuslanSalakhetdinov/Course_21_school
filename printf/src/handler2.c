/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.21-shool.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 13:39:19 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/08/16 13:39:21 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			handle_u(t_prf *prf, va_list ap)
{
	unsigned long long int	n;
	char					*s;

	n = unsigned_handle_mod(prf, ap);
	s = pf_dtoa_u(n, 10, 0);
	return (write_unsigned(prf, n, s, NULL));
}

int			handle_o(t_prf *prf, va_list ap)
{
	unsigned long long int	n;
	char					*s;

	n = unsigned_handle_mod(prf, ap);
	s = pf_dtoa_u(n, 8, 0);
	if (prf->hash_flag)
	{
		prf->precision_flag = 1;
		if (!n)
			prf->precision = MAX(prf->precision, 1);
		else
			prf->precision = MAX(prf->precision, (int)ft_strlen(s) + 1);
	}
	return (write_unsigned(prf, n, s, NULL));
}

int			handle_x(t_prf *prf, va_list ap)
{
	unsigned long long int	n;
	char					*s;
	char					*prepend;
	char					hex_char;

	n = unsigned_handle_mod(prf, ap);
	hex_char = prf->type == 6 ? 'a' : 'A';
	s = pf_dtoa_u(n, 16, hex_char);
	if (prf->hash_flag && n)
	{
		prepend = prf->type == 6 ? "0x" : "0X";
		prf->prepend = 1;
	}
	return (write_unsigned(prf, n, s, (prf->prepend ? prepend : NULL)));
}

inline int	is_signed_conv(int c)
{
	if (c == 3)
		return (1);
	else
		return (0);
}

int			prf_len(t_prf *prf, int len, char *prepend)
{
	int b_len;

	b_len = (prf->precision_flag && prf->precision > len ? prf->precision : len);
	b_len += (is_signed_conv(prf->type) && (prf->space_flag ||
		prf->plus_flag || prf->is_neg) ? 1 : 0);
	if (prf->prepend)
		b_len += ft_strlen(prepend);
	return (b_len);
}
