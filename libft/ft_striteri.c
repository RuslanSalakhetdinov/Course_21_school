/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:09:42 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/25 07:04:59 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_striteri(char *s, void (*f) (unsigned int, char *))
{
	unsigned int	i;

	if (s && (*f))
	{
		i = 0;
		while (*s)
			(*f)(i++, s++);
	}
}
