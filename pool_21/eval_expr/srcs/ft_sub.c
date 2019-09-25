/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 17:51:59 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/18 22:57:57 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

t_list	*ft_sub(t_list **b_sub)
{
	t_list *sub;

	sub = *b_sub;
	sub->prev->nbr -= sub->next->nbr;
	*b_sub = sub;
	sub = sub->next;
	ft_delete(&sub);
	ft_delete(&sub);
	return (sub);
}
