/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 22:46:46 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/06 23:35:20 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	if (i == size)
		return (size);
	j = 0;
	size -= i;
	while (src[j] != '\0' && size > 1)
	{
		dest[i + j] = src[j];
		j++;
		size--;
	}
	dest[i + j] = '\0';
	return (i + j);
}
