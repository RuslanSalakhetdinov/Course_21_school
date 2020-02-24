/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:29:43 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/26 20:08:03 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	char	*buf;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	buf = (char*)malloc(sizeof(*buf) * (len + 1));
	if (!buf)
		return (NULL);
	i = 0;
	while (i < len)
	{
		buf[i] = (char)s[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
