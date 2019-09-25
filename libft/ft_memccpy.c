/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:40:36 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/24 21:32:58 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	const unsigned char	*buf_src;
	unsigned char		*buf_dst;

	buf_src = (const unsigned char*)src;
	buf_dst = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		buf_dst[i] = buf_src[i];
		if (buf_dst[i] == (unsigned char)c)
			return (&buf_dst[i + 1]);
		i++;
	}
	return (NULL);
}
