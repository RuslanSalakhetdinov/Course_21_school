/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:35:38 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/13 13:28:43 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	int i;
	int j;

	if (!needle)
		return (haystack);
	i = -1;
	while (haystack[++i] && n)
	{
		j = -1;
		while (neddle[++j] == haystack[i + j])
			if (!needle[j + 1])
				return (haystack + i);
		n--;
	}
	return (NULL);
}
