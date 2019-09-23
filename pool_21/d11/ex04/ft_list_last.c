/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 17:07:13 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/14 21:14:20 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_last(t_list *begin_list)
{
	t_list	*list;

	if (begin_list == NULL)
		return (NULL);
	list = begin_list;
	while (list->next != NULL)
		list = list->next;
	return (list);
}
