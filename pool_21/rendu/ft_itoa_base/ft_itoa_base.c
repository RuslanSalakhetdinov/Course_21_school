/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 16:29:30 by exam              #+#    #+#             */
/*   Updated: 2019/08/16 16:31:33 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *if_min_int(char *str)
{
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	return (str);
}

char ret_dig(int nbr)
{
	if (nbr >= 0 && nbr <= 9)
		return ('0' + nbr);
	if (nbr >= 10 && nbr <= 15)
		return ('A' + (nbr - 10));
	return ('\0');
}

char *ft_itoa_base(int value, int base)
{
	char *buf;
	int i;
	int suff;

	buf = (char*)malloc(33 * sizeof(buf));
	if (buf)
	{
		i = -1;
		while (++i < 33)
			buf[i] = '\0';
	}
	else
		return (NULL);
	if (value == -2147483648)
		return (if_min_int(buf));
	suff = 1;
	if (value < 0)
	{
		suff = -1;
		value = value * suff;
	}
	while (value / base)
	{
		buf[--i] = ret_dig(value % base);
		value = value / base;
	}
	buf[--i] = ret_dig(value);
	if (suff == -1)
		buf [--i] = '-';
	buf = &buf[i];
	return (buf);
}
