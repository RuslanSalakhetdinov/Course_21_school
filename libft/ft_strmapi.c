/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:31:56 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/25 07:07:50 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char			*buf;
	unsigned int	i;

	if (!s || !(*f))
		return (NULL);
	buf = (char*)malloc(sizeof(*buf) * (ft_strlen((char*)s) + 1));
	if (!buf)
		return (NULL);
	i = 0;
	while (s[i])
	{
		buf[i] = (*f)(i, s[i]);
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
