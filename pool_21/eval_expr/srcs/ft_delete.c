/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 17:21:49 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/18 17:57:30 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

void	ft_delete(t_list **begin_list)
{
	t_list *buf;
	t_list *list;

	list = *begin_list;
	if (list)
	{
		if (list->prev)
		{
			buf = list;
			list = list->prev;
			*begin_list = list;
			list->next = NULL;
			free(buf);
		}
		else
			free(list);
	}
}
