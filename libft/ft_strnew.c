/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:39:57 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/23 23:38:36 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnew(size_t size)
{
	unsigned char	*str;

str = (unsigned char*)malloc(sizeof(*str) * (size + 1));
	if (!str)
		return (NULL);
	size += 2;
	while (--size)
		str[size] = '\0';
	return ((char*)str);
}
