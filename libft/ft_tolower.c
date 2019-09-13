/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:56:44 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/13 13:59:17 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_tolower(int c)
{
	unsigned char	buf;

	buf = (unsigned char)c;
	if (buf >= 'A' && buf <= 'Z')
		return (c + 32);
	return (c);
}
