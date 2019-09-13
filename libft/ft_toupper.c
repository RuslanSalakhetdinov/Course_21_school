/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:49:03 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/13 13:56:19 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_toupper(int c)
{
	unsigned char	buf;

	buf = (unsigned char)c;
	if (buf >= 'a' && buf <= 'z')
		return (c - 32);
	return (c);
}
