/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:21:42 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/11/29 15:33:48 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		form_del(t_form **main)
{
	t_form	*buf;
	int		i;

	if (*main)
	{
		buf = (*main);
		while (!buf)
		{
			buf = buf->link;
			i = -1;
			while (++i < 5)
				free(((*main)->f)[i]);
			free((*main)->f);
			free((*main));
			(*main) = buf;
		}
	}
}
