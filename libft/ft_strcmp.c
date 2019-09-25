/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:35:03 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/25 00:04:33 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*buf1;
	unsigned char	*buf2;

	buf1 = (unsigned char *)s1;
	buf2 = (unsigned char *)s2;
	while (*buf1 == *buf2 && *buf1)
	{
		buf1++;
		buf2++;
	}
	return (*buf1 - *buf2);
}
