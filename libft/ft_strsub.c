/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:44:02 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/11 16:45:27 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*buf;
	unsigned int	i;

	buf = (char*)malloc(sizeof(*buf) * (len + 1));
	if (!buf)
		return (NULL);
	while (i < len)
		buf[i++] = s[len + i];
	return (buf);
}
