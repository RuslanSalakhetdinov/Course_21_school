/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:45:35 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/11 16:46:16 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char *buf;
	char *end;

	buf = (char*)s;
	while (*buf == ' ' || *buf == '\t' || *buf == '\n')
		buf++;
	end = buf;
	while (*end)
		end++;
	while (*end == ' ' || *end == '\t' || *end == '\n')
		*end-- = '\0';
	return (ft_strdup(buf));
}
