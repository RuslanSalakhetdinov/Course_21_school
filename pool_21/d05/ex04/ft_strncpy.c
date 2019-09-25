/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 23:39:02 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/06 23:39:24 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char *buff_dest;

	buff_dest = dest;
	while (n > 0)
	{
		if (*src != '\0')
			*dest++ = *src++;
		else
			*dest++ = '\0';
		n--;
	}
	return (buff_dest);
}
