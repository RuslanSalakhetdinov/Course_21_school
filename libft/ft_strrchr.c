/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:29:00 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/23 23:47:22 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int *c)
{
	char *buf;

	buf = NULL;
	while (*s)
	{
		if(*s == (char)c)
			buf = (char *)s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (buf);
}
