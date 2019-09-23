/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 15:19:48 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/14 16:06:01 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *list;

	list = *begin_list;
	if (*begin_list == NULL)
		*begin_list = ft_create_elem(data);
	else
	{
		while (list->next != NULL)
			list = list->next;
		list->next = ft_create_elem(data);
	}
}
