/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:31:56 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/11 16:34:24 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char			*buf;
	unsigned int	i;

	buf = (char*)malloc(sizeof(*buf) * ft_strlen((char*)s));
	if (!buf)
		return (NULL);
	i = 0;
	while (s[i])
		buf[i] = (*f)(i, s[i++]);
	return (buf);
}
