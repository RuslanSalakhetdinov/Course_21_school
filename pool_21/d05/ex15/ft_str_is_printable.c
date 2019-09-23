/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 21:25:18 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/06 22:02:27 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_if(char c)
{
	if (c >= 0 && c <= 31)
		return (0);
	else
		return (1);
}

int		ft_str_is_printable(char *str)
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
