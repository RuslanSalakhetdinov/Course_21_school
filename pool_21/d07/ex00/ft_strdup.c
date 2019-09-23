/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 00:50:43 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/08 23:39:24 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	char *buff_dest;

	buff_dest = dest;
	while (*src != '\0')
		*dest++ = *src++;
	*dest = '\0';
	return (buff_dest);
}

int		ft_strlen(char *str)
{
	int e_num;

	e_num = 0;
	while (*str != '\0')
	{
		str++;
		e_num++;
	}
	return (e_num);
}

void	*ft_strdup(char *src)
{
	char	*dest;
	int		len;

	len = ft_strlen(src);
	dest = (char*)malloc((len + 1) * sizeof(char));
	dest = ft_strcpy(dest, src);
	return (dest);
}
