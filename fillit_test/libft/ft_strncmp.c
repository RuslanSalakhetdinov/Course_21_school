/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:35:15 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/25 06:24:57 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*buf1;
	unsigned char	*buf2;
	size_t			i;

	buf1 = (unsigned char *)s1;
	buf2 = (unsigned char *)s2;
	i = -1;
	while (++i < n - 1 && *buf1 == *buf2 && *buf1)
	{
		buf1++;
		buf2++;
	}
	if (!n)
		return (0);
	return (*buf1 - *buf2);
}
