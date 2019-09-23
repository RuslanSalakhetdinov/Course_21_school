/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:32:44 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/23 23:19:29 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int *c)
{
	while (*s)
	{
		if(*s == (char)c)
			return ((char*)s);
		s++;
	}
	if (*s == (char)c)
		return ((char*)s);
	return (NULL);
}
