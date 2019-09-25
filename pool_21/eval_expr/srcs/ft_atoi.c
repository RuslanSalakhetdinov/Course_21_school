/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 11:42:16 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/18 17:55:07 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

int			ft_atoi(char **src)
{
	int		nb;
	int		suff;
	char	*str;

	str = *src;
	nb = 0;
	suff = 1;
	while (*str == '\0' || *str == '\n' || *str == '\t' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-')
	{
		str += 1;
		suff *= -1;
	}
	if (*str == '+')
		str += 1;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		nb = (*str - '0') + 10 * nb;
		str += 1;
	}
	str--;
	*src = str;
	return (nb *= suff);
}
