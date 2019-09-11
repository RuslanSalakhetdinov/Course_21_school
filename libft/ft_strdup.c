/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:04:51 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/11 15:06:41 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *s)
{
	const char	*buf;
	int			len;

	len = ft_strlen(s);
	buf = (const char*)malloc(sizeof(*buf) * (len + 1));
	if (!buf)
		return (NULL);
	len = -1;
	while (++len < ft_strlen(s))
		buf[len] = s[len];
	buf[len] = '\0';
	return (buf);
}
