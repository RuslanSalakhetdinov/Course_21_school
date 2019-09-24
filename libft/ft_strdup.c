/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:29:43 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/24 20:16:25 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	char	*buf;
	size_t		len;

len = ft_strlen(s);
	buf = (char*)malloc(sizeof(*buf) * (len + 1));
	if (!buf)
		return (NULL);
	len = -1;
	while (++len < ft_strlen(s))
		buf[len] = (char)s[len];
	buf[len] = '\0';
	return (buf);
}
