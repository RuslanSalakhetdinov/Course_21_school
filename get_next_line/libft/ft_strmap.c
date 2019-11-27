/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:19:27 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/25 07:06:47 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f) (char))
{
	char	*buf;
	int		i;

	if (!s || !(*f))
		return (NULL);
	buf = (char*)malloc(sizeof(*buf) * (ft_strlen((char*)s) + 1));
	if (!buf)
		return (NULL);
	i = 0;
	while (s[i])
	{
		buf[i] = (*f)(s[i]);
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
