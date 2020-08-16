/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.21-shool.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 13:39:50 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/08/16 13:39:52 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		places(unsigned long long n, int base)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		++count;
		n /= base;
	}
	return (count);
}

char	*pf_dtoa_signed(long long int n)
{
	char				*s;
	int					i;

	i = places(n < 0 ? -n : n, 10);
	if (!(s = (char*)ft_memalloc(i + 1)))
		return (NULL);
	if (n == 0)
		s[0] = '0';
	while (n)
	{
		s[--i] = ((n > 0) ? (n % 10) : -(n % 10)) + '0';
		n /= 10;
	}
	return (s);
}

char	*pf_dtoa_u(unsigned long long int n, int base, char c)
{
	char				*s;
	int					i;

	i = places(n, base);
	if (!(s = (char*)ft_memalloc(i + 1)))
		return (NULL);
	if (n == 0)
		s[0] = '0';
	while (n)
	{
		s[--i] = (n % base > 9) ? (n % base - 10 + c) : (n % base + '0');
		n /= base;
	}
	return (s);
}

void	write_padding(int len, char c)
{
	while (len)
	{
		write(1, &c, 1);
		--len;
	}
}

int		write_unsigned(t_prf *prf, unsigned long long n,
	char *s, char *prepend)
{
	int len;
	int b_len;

	flag_manager(prf);
	if (prf->type == 'o' && prf->hash_flag)
	{
		prf->precision = (prf->precision_flag && prf->precision > (int)ft_strlen(s) + 1)
			? prf->precision : ft_strlen(s) + 1;
		prf->precision_flag = 1;
	}
	len = prf->precision_flag && !prf->precision && n == 0 ? 0 : ft_strlen(s);
	b_len = prf_len(prf, len, prepend);
	pad_prf(prf, len, b_len, START);
	if (prf->prepend)
		write(1, prepend, ft_strlen(prepend));
	pad_prf(prf, len, b_len, ZEROS);
	write(1, s, len);
	pad_prf(prf, len, b_len, END);
	free(s);
	return (prf->width > b_len ? prf->width : b_len);
}
