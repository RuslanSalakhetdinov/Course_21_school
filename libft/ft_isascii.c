/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:46:48 by cwheatgr          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/09/24 21:09:42 by cwheatgr         ###   ########.fr       */
=======
/*   Updated: 2019/09/24 17:57:05 by cwheatgr         ###   ########.fr       */
>>>>>>> 23ff7f19a67e1f39972f88117e15b9ee011240c8
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_isascii(int c)
{
<<<<<<< HEAD
	if (c >= 0 && c <= 127)
=======
	unsigned char	buf;

	buf = (unsigned char)c;
	if (buf <= 127)
>>>>>>> 23ff7f19a67e1f39972f88117e15b9ee011240c8
		return (1);
	return (0);
}
