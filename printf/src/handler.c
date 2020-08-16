/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.21-shool.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 13:39:09 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/08/16 13:39:11 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_c(t_prf *prf, va_list ap)
{
	char c;

	c = va_arg(ap, int);
	if (prf->width && !prf->minus_flag && !prf->zero_flag)
		write_padding(prf->width - 1, ' ');
	if (prf->width && !prf->minus_flag && prf->zero_flag)
		write_padding(prf->width - 1, '0');
	write(1, &c, 1);
	if (prf->width && prf->minus_flag)
		write_padding(prf->width - 1, ' ');
	return (prf->width ? prf->width : 1);
}

int	handle_percent(t_prf *prf)
{
	if (prf->width && !prf->zero_flag && !prf->minus_flag)
		write_padding(prf->width - 1, ' ');
	if (prf->width && prf->zero_flag && !prf->minus_flag)
		write_padding(prf->width - 1, '0');
	write(1, "%", 1);
	if (prf->width && prf->minus_flag)
		write_padding(prf->width - 1, ' ');
	return (prf->width ? prf->width : 1);
}

int	handle_s(t_prf *prf, va_list ap)
{
	char	*s;
	int		len;

	s = va_arg(ap, char*);
	len = s ? ft_strlen(s) : 6;
	if (prf->precision_flag && prf->precision < len)
		len = prf->precision;
	if (prf->width && !prf->minus_flag && !prf->zero_flag
		&& prf->width > len)
		write_padding(prf->width - len, ' ');
	if (prf->width && !prf->minus_flag && prf->zero_flag
		&& prf->width > len)
		write_padding(prf->width - len, '0');
	s ? write(1, s, len) : write(1, "(null)", len);
	if (prf->width && prf->minus_flag && prf->width > len)
		write_padding(prf->width - len, ' ');
	return (prf->width > len ? prf->width : len);
}

int	handle_p(t_prf *prf, va_list ap)
{
	void	*p;
	char	*s;
	int		len;
	int		b_len;

	p = va_arg(ap, void*);
	s = ft_ptoa(p, 'a')	;
	prf->prepend = 1;
	len = (prf->precision_flag && !prf->precision && !p ? 0 : ft_strlen(s));
	b_len = prf_len(prf, len, "0x");
	pad_prf(prf, len, b_len, START);
	write(1, "0x", 2);
	pad_prf(prf, len, b_len, ZEROS);
	write(1, s, len);
	pad_prf(prf, len, b_len, END);
	free(s);
	return (MAX(prf->width, b_len));
}

int	handle_d(t_prf *prf, va_list ap)
{
	long long int	n;
	char			sign;
	char			*s;
	int				len;
	int				b_len;

	n = signed_handle_mod(prf, ap);
	s = pf_dtoa_signed(n);
	flag_manager(prf);
	sign = set_sign(n, prf);
	len = prf->precision_flag && !prf->precision && n == 0 ? 0 : ft_strlen(s);
	b_len = prf_len(prf, len, NULL);
	pad_prf(prf, len, b_len, START);
	if (n < 0 || prf->plus_flag || prf->space_flag)
		write(1, &sign, 1);
	pad_prf(prf, len, b_len, ZEROS);
	write(1, s, len);
	pad_prf(prf, len, b_len, END);
	free(s);
	return (prf->width > b_len ? prf->width : b_len);
}
