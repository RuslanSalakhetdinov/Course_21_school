/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 18:01:03 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/18 18:41:32 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

t_list	*ft_div(t_list **b_div)
{
	t_list *div;

	div = *b_div;
	div->prev->nbr /= div->next->nbr;
	*b_div = div;
	div = div->next;
	ft_delete(&div);
	ft_delete(&div);
	return (div);
}
