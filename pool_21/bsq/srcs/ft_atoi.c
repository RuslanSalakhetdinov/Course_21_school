/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 11:42:16 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/22 10:45:00 by knarwhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int			ft_atoi(char **src, int **params)
{
	int		nb;
	int		suff;
	char	*str;

	str = *src;
	nb = 0;
	suff = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		suff *= -1;
		str++;
	}
	if (*str == '+')
		str++;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		nb = (*str - '0') + 10 * nb;
		str++;
	}
	*src = str;
	if (*str)
		printerror(params);
	return (nb *= suff);
}
