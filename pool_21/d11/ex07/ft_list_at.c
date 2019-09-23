/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 20:42:11 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/14 22:39:16 by cwheatgr         ###   ########.fr       */
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

t_list		*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	int		counter;
	t_list	*list;

	list = begin_list;
	if (list == NULL || (int)nbr > ft_list_size(list))
		return (NULL);
	counter = -1;
	while (++counter != (int)nbr)
		list = list->next;
	return (list);
}
