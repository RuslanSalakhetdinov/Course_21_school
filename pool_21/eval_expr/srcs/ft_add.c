/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:56:44 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/18 18:43:50 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

t_list	*ft_add(t_list **b_add)
{
	t_list *add;

	add = *b_add;
	add->prev->nbr += add->next->nbr;
	*b_add = add;
	add = add->next;
	ft_delete(&add);
	ft_delete(&add);
	return (*b_add);
}
