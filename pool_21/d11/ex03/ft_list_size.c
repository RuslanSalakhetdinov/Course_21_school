/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 16:52:32 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/14 22:14:49 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int			ft_list_size(t_list *begin_list)
{
	int		counter;
	t_list	*list;

	if (begin_list == NULL)
		return (0);
	counter = 1;
	list = begin_list;
	while (list->next != NULL)
	{
		list = list->next;
		counter++;
	}
	return (counter);
}
