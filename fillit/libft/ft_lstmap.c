/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:01:00 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/26 23:21:49 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lst_del_one(t_list **alst)
{
	t_list	*list;

	list = *alst;
	free(list);
	*alst = NULL;
}

static void	ft_lst_del(t_list **alst)
{
	t_list	*nlst;
	t_list	*plst;

	plst = *alst;
	while (plst)
	{
		nlst = plst->next;
		ft_lst_del_one(&plst);
		plst = nlst;
	}
	*alst = NULL;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*nlst;
	t_list	*start;

	if (!lst || !(*f))
		return (NULL);
	nlst = (*f)(lst);
	start = nlst;
	while (lst->next)
	{
		lst = lst->next;
		if (!(*f)(lst))
		{
			ft_lst_del(&start);
			return (NULL);
		}
		nlst->next = (*f)(lst);
		nlst = nlst->next;
	}
	return (start);
}
