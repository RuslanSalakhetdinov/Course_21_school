/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:36:08 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/20 19:36:12 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*if_min_int(char *str)
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

void	ft_algo_play(int *suff, char **buf)
{
	int i;

	*suff = 1;
	if (n < 0)
	{
		*suff = -1;
		n = n * (*suff);
	}
	while (n / 10)
	{
		buf[--i] = '0' + n % 10;
		n = n / 10;
	}
	(*buf)[--i] = '0' + n;
	if (*suff == -1)
		(*buf)[--i] = '-';
	(*buf) = &(*buf)[i];
}

char	*ft_itoa(int n)
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
	if (n == -2147483648)
		return (if_min_int(buf));
	ft_algo_paly(&suff, &buf);
	return (buf);
}
