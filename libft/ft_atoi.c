/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:35:53 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/20 19:35:56 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int nb;
	int suff;

	nb = 0;
	suff = 1;
	while (*nptr == '\0' || *nptr == '\n' || *nptr == '\t' || *nptr == '\v' \
			|| *nptr == '\f' || *nptr == '\r' || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
	{
		nptr += 1;
		suff *= -1;
	}
	if (*nptr == '+')
		nptr += 1;
	while (*nptr != '\0' && *nptr >= '0' && *nptr <= '9')
	{
		nb = (*nptr - '0') + 10 * nb;
		nptr += 1;
	}
	return (nb *= suff);
}
