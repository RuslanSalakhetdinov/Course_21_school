/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:01:00 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/20 20:01:54 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list *nlst;
	t_list *start;

	if (!lst || !(*f))
		return (NULL);
	nlst = (*f)(lst);
	start = nlst;
	while (lst->next)
	{
		lst = lst->next;
		if (!(*f)(lst))
		{
			ft_lstdel(start);
			return (NULL);
		}
		nlst->next = (*f)(lst);
		nlst = nlst->next;
	}
	return (start);
}
