/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:00:51 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/24 18:46:07 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memalloc(size_t size)
{
	unsigned char	*area;

	area = (unsigned char*)malloc(sizeof(*area) * size);
	if (!area)
		return (NULL);
	while (size)
		area[--size] = 0;
	return (area);
}
