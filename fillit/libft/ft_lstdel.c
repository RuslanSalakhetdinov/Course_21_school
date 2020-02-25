/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:43:27 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/26 23:13:31 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list *nlst;
	t_list *plst;

	plst = *alst;
	while (plst)
	{
		nlst = plst->next;
		ft_lstdelone(&plst, (*del));
		plst = nlst;
	}
	*alst = NULL;
}
