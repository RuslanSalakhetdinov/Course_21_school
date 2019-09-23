/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:40:36 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/23 23:02:12 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const unsigned char	*buf_src;
	unsigned char		*buf_dst;

	buf_src = (const unsigned char*)src;
	buf_dst = (unsigned char*)dst;
	while (n--)
	{
		*buf_dst = *buf_src;
		if (*buf_dst == (unsigned char)c)
			return (++buf_dst);
		buf_dst++;
		buf_src++;
	}
	return (NULL);
}
