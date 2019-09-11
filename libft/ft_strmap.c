/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:19:27 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/11 16:31:42 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f) (char))
{
	char	*buf;
	int		i;

	buf = (char*)malloc(sizeof(*buf) * ft_strlen((char*)s));
	if (!buf)
		return (NULL);
	i = 0;
	while (s[i])
		buf[i] = (*f)(s[i++]);
	return (buf);
}
