/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.21-shool.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 13:39:37 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/08/16 13:39:39 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			parse_modifier(const char *s, t_prf *prf)
{
	char		*ptr;
	static char	key[] = "hlL";

	if (ft_strnstr(s, "hh", 2))
	{
		prf->modifier = 1;
		return (2);
	}
	else if (ft_strnstr(s, "ll", 2))
	{
		prf->modifier = 5;
		return (2);
	}
	else if ((ptr = ft_strchr(key, *s)) && *s)
	{
		prf->modifier = ptr - key + 2;
		return (1);
	}
	return (0);
}

const char	*parse_flag(const char *s, t_prf *prf)
{
	while (ft_strchr("#0-+ ", *s) && *s)
	{
		if (*s == '#')
			prf->hash_flag = 1;
		else if (*s == '0')
			prf->zero_flag = 1;
		else if (*s == '-')
			prf->minus_flag = 1;
		else if (*s == '+')
			prf->plus_flag = 1;
		else if (*s == ' ')
			prf->space_flag = 1;
		++s;
	}
	return (s);
}

const char	*parse_width(const char *s, t_prf *prf, va_list ap)
{
	int star_flag;

	star_flag = 0;
	if (*s == '*')
	{
		star_flag = handle_star_width(prf, ap, star_flag);
		++s;
	}
	while (*s >= '0' && *s <= '9')
	{
		if (!(prf->width) || star_flag)
			prf->width = ft_atoi(s);
		++s;
	}
	if (*s == '*')
	{
		star_flag = handle_star_width(prf, ap, star_flag);
		++s;
	}
	return (s);
}

const char	*parse_precision(const char *s, t_prf *prf, va_list ap)
{
	int garbage;

	if (*s == '.')
	{
		prf->precision_flag = 1;
		++s;
	}
	while (*s >= '0' && *s <= '9' && prf->precision_flag)
	{
		if (!(prf->precision))
			prf->precision = ft_atoi(s);
		++s;
	}
	if (*s == '*' && prf->precision_flag)
	{
		if (!prf->precision)
			prf->precision = va_arg(ap, int);
		else
			garbage = va_arg(ap, int);
		if (prf->precision < 0)
			prf->precision_flag = 0;
		++s;
	}
	return (s);
}

const char	*parse_type(const char *s, t_prf *prf)
{
	static char key[] = "cspdouxXf%";

	if ((ft_strchr(key, *s) || *s == 'i') && *s)
	{
		prf->type = ft_strchr(key, *s) - key;
		if (*s == 'i')
			prf->type = 3;
		prf->valid = 1;
		++s;
	}
	return (s);
}
