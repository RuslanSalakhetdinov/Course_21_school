/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 18:31:27 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/18 23:33:39 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

t_list	*ft_create_elem(char sbl, int nbr)
{
	t_list *new_list;

	new_list = (t_list*)malloc(sizeof(t_list));
	if (new_list)
	{
		new_list->sbl = sbl;
		new_list->nbr = nbr;
		new_list->next = NULL;
		new_list->prev = NULL;
	}
	return (new_list);
}
