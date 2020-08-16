/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.21-shool.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 13:37:33 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/08/16 13:38:46 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			prf_parser(const char *s, t_prf *prf, va_list ap)
{
	const char *start;

	start = s;
	s = parse_flag(s, prf);
	s = parse_width(s, prf, ap);
	s = parse_precision(s, prf, ap);
	s += parse_modifier(s, prf);
	s = parse_type(s, prf);
	return (s - start);
}

int			get_handler(t_prf *prf, va_list ap)
{
	static int	(*handlers[9])(t_prf *prf, va_list ap) = {
		&handle_c,
		&handle_s,
		&handle_p,
		&handle_d,
		&handle_o,
		&handle_u,
		&handle_x,
		&handle_x,
		&handle_f
	};
	static int	(*handle_percent_ptr)(t_prf *prf) = &handle_percent;

	if (prf->type == 9)
		return (handle_percent_ptr(prf));
	return ((handlers[prf->type](prf, ap)));
}

void		text_write(const char **s, int *pos)
{
	int		len;
	char	*next;

	next = ft_strchr(*s, '%');
	len = next ? next - *s : ft_strlen(*s);
	write(1, *s, len);
	*s += len;
	*pos += len;
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	t_prf	prf;
	int		pos;

	ft_bzero(&prf, sizeof(prf));
	pos = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format += prf_parser(format + 1, &prf, ap) + 1;
			if (prf.valid)
				pos += get_handler(&prf, ap);
			ft_bzero(&prf, sizeof(prf));
		}
		else
			text_write(&format, &pos);
	}
	va_end(ap);
	return (pos);
}
