/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 17:21:13 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/17 16:23:47 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

int		ft_valid(int argc, char **argv)
{
	if (argc != 4)
		return (-1);
	if (argv[2][1])
		return (-1);
	if (argv[2][0] == '+')
		return (0);
	if (argv[2][0] == '-')
		return (1);
	if (argv[2][0] == '/')
		return (2);
	if (argv[2][0] == '%')
		return (3);
	if (argv[2][0] == 42)
		return (4);
	return (21);
}
