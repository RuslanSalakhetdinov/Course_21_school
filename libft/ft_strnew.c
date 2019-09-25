/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:39:57 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/25 01:12:56 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnew(size_t size)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char*)malloc(sizeof(*str) * (size + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < size + 1)
		str[i] = '\0';
	return ((char*)str);
}
