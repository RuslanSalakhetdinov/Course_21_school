/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:37:18 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/20 20:21:38 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	if (!needle)
		return (haystack);
	i = -1;
	while (haystack[++i])
	{
		j = -1;
		while (neddle[++j] == haystack[i + j])
			if (!needle[j + 1])
				return (haystack + i);
	}
	return (NULL);
}
