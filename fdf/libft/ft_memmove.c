/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:13:24 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/25 02:23:40 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_buf;
	unsigned char	*src_buf;

	dst_buf = (unsigned char*)dst;
	src_buf = (unsigned char*)src;
	if (src_buf < dst_buf)
		while (len--)
			dst_buf[len] = src_buf[len];
	else
		ft_memcpy(dst_buf, src_buf, len);
	return (dst);
}
