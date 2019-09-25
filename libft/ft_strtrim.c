/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:45:31 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/25 07:17:23 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*buf;
	int		start;
	size_t	len;

	if (!s)
		return (NULL);
	if (!*s)
		return (ft_strdup(s));
	buf = (char*)s;
	start = 0;
	while (*buf == ' ' || *buf == '\t' || *buf == '\n')
	{
		buf++;
		start++;
	}
	if (!s[start])
		return (ft_strdup("\0"));
	len = ft_strlen(s) - 1;
	while ((s[len] == ' ' || s[len] == '\t' || s[len] == '\n') && len > 0)
		len--;
	return (ft_strsub(s, start, len - start + 1));
}
