/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 15:40:46 by exam              #+#    #+#             */
/*   Updated: 2019/08/16 16:10:02 by exam             ###   ########.fr       */
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

char *ft_itoa(int nbr)
{
	char *buf;
	int i;
	int suff;

	buf = (char*)malloc(12 * sizeof(buf));
	if (buf)
	{
		i = -1;
		while (++i < 12)
			buf[i] = '\0';
	}
	else
		return (NULL);
	if (nbr == -2147483648)
		return (if_min_int(buf));
	suff = 1;
	if (nbr < 0)
	{
		suff = -1;
		nbr = nbr * suff;
	}
	while (nbr / 10)
	{
		buf[--i] = '0' + nbr % 10;
		nbr = nbr / 10;
	}
	buf[--i] = '0' + nbr;
	if (suff == -1)
		buf [--i] = '-';
	buf = &buf[i];
	return (buf);
}
