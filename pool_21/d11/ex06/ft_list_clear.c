/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 17:40:05 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/17 18:32:42 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list *list;

	while (*begin_list != NULL)
	{
		list = *begin_list;
		*begin_list = (*begin_list)->next;
		free(list);
	}
}
