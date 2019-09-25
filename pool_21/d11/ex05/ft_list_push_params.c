/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 17:15:13 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/14 22:30:40 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_push_params(int ac, char **av)
{
	t_list	*new_list;
	t_list	*prev_list;
	int		i;

	i = -1;
	prev_list = NULL;
	while (++i < ac)
	{
		new_list = ft_create_elem(av[i]);
		new_list->next = prev_list;
		prev_list = new_list;
	}
	return (prev_list);
}
