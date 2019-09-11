/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:13:24 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/11 18:03:26 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_buf;
	unsigned char	*src_buf;
	unsigned char	*str;

	dst_buf = (unsigned char)dst;
	src_buf = (unsigned char)src;
	str = (unsigned char*)malloc(sizeof(*str) * (ft_strlen(src_buf) + 1));
	if (!str || !len)
		return ;
	ft_memcpy(str, src_buf);
	ft_memcpy(dst_buf, str);
	free(str);
	return (dst);
}
