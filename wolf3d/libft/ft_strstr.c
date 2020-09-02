/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.21-shool.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 15:02:25 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/08/08 15:02:27 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char *a;
	char *b;

	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1)
	{
		a = (char *)s1;
		b = (char *)s2;
		while (*b && *a == *b)
		{
			a++;
			b++;
		}
		if (*b == '\0')
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
