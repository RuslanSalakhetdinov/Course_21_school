/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 14:36:02 by exam              #+#    #+#             */
/*   Updated: 2019/08/16 14:57:09 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strdup(char *src)
{
	char	*dup;
	char	*buf;
	int		coun;

	buf = src;
	coun = 1;
	while (*buf++)
		coun++;
	dup = (char*)malloc(coun * sizeof(*dup));
	if (dup)
	{
	buf = src;
	coun = 0;
	while (*buf)
	{
		dup[coun] = *buf;
		coun++;
		buf++;
	}
	dup[coun] = '\0';
	return (dup);
	}
	return (NULL);
}
