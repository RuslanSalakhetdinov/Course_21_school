/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:13:24 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/23 23:14:48 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_buf;
	unsigned char	*src_buf;
	unsigned char	*str;

	dst_buf = (unsigned char*)dst;
	src_buf = (unsigned char*)src;
	str = (unsigned char*)malloc(sizeof(*str) * \
			(ft_strlen((const char *)src_buf) + 1));
	if (!str || !len)
		return (NULL);
	ft_memcpy(str, src_buf, len);
	ft_memcpy(dst_buf, str, len);
	free(str);
	return (dst);
}
