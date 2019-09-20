/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:43:27 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/20 20:00:04 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list *nlst;
	t_list *plst;

	plst = *alst;
	while (plst)
	{
		nlst = plist->next;
		ft_lstdelone(&plist, (*del));
		plst = nlst;
	}
	*alst = NULL;
}
