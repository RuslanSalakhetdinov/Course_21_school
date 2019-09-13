/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:18:30 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/13 14:42:55 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_lstdelone(t_list **alst, void (*del) (void *, size_t))
{
	t_list *list;

	list = *alst;
	(*del)(list->content, list->content_size);
	free(*list);
	*alst = NULL;
}
