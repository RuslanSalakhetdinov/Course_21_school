/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:29:00 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/20 20:20:12 by cwheatgr         ###   ########.fr       */
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
			buf = s;
		s++;
	}
	if (*s = (char)c)
		return (s);
	return (buf);
}
