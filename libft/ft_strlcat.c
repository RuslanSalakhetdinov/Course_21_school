/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:14:23 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/11 15:18:00 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst[i] != '\0')
		i++;
	if (i == size)
		return (size);
	j = 0;
	size -= i;
	while (src[j] != '\0' && size > 1)
	{
		dst[i + j] = src[j];
		j++;
		size--;
	}
	dst[i + j] = '\0';
	return (i + j);
}
