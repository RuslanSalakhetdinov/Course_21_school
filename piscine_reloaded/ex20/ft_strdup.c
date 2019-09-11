/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:07:54 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/04 13:05:28 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_strlen(char *str)
{
	int		num;

	num = 0;
	if (!str)
		return (0);
	while (*str++)
		num++;
	return (num);
}

char		*ft_strdup(char *src)
{
	char	*buf;
	int		i;

	buf = malloc(sizeof(*buf) * (ft_strlen(src) + 1));
	if (buf)
	{
		i = -1;
		while (++i < ft_strlen(src))
			buf[i] = src[i];
		buf[i] = '\0';
	}
	return (buf);
}
