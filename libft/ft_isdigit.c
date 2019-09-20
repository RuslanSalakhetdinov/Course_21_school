/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:43:30 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/13 13:44:22 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_isdigit(int c)
{
	unsigned char	buf;

	buf = (unsigned char)c;
	if (buf >= '0' && buf <= '9')
		return (1);
	return (0);
}