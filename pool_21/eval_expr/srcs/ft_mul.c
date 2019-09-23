/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 17:53:17 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/18 18:39:05 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

t_list	*ft_mul(t_list **b_mul)
{
	t_list *mul;

	mul = *b_mul;
	mul->prev->nbr *= mul->next->nbr;
	*b_mul = mul;
	mul = mul->next;
	ft_delete(&mul);
	ft_delete(&mul);
	return (mul);
}
