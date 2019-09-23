/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:48:22 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/06 20:50:14 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_if(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

int		ft_str_is_lowercase(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str != '\0')
	{
		if (ft_if(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}
