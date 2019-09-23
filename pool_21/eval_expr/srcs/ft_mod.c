/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 18:01:56 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/18 18:44:07 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

t_list	*ft_mod(t_list **b_mod)
{
	t_list *mod;

	mod = *b_mod;
	mod->prev->nbr %= mod->next->nbr;
	*b_mod = mod;
	mod = mod->next;
	ft_delete(&mod);
	ft_delete(&mod);
	return (mod);
}
