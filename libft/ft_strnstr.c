/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:35:38 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/25 06:42:42 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	i = -1;
	n++;
	while (haystack[++i] && --n)
	{
		j = 0;
		while (needle[j] == haystack[i + j])
		{
			if (!needle[j + 1] && n >= j)
				return ((char *)haystack + i);
			j++;
		}
	}
	return (NULL);
}
