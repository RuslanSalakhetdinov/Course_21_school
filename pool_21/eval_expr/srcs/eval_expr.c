/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 19:35:16 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/18 23:37:08 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

void		ft_addtol(t_list **list, char sbl, int nbr)
{
	t_list	*p;
	t_list	*n;

	n = *list;
	while (n->next)
		n = n->next;
	p = n;
	n = ft_create_elem(sbl, nbr);
	n->prev = p;
	p->next = n;
	*list = n;
}

void		ft_if_c(char **buf, t_list **list)
{
	if (**buf == ')')
	{
		while ((*list)->sbl != '(')
		{
			*list = (*list)->prev;
			if ((*list)->sbl == '+')
				*list = ft_add(list);
			else if ((*list)->sbl == '-')
				*list = ft_sub(list);
		}
		(*list)->nbr = (*list)->next->nbr;
		(*list)->sbl = '\0';
		*list = (*list)->next;
		ft_delete(list);
	}
}

void		ft_if_o(t_list **list)
{
	while ((*list)->sbl != 'a')
	{
		*list = (*list)->prev;
		if ((*list)->sbl == '+')
			*list = ft_add(list);
		else if ((*list)->sbl == '-')
			*list = ft_sub(list);
	}
	*list = (*list)->next;
}

void		ft_if_d(char **buf, t_list **list)
{
	if (**buf >= '0' && **buf <= '9')
	{
		ft_addtol(list, '\0', ft_atoi(buf));
		if ((*list)->prev->sbl == '*' || (*list)->prev->sbl == '/' \
				|| (*list)->prev->sbl == '%')
			*list = (*list)->prev;
		if ((*list)->sbl == '*')
			*list = ft_mul(list);
		if ((*list)->sbl == '/')
			*list = ft_div(list);
		if ((*list)->sbl == '%')
			*list = ft_mod(list);
	}
}

int			eval_expr(char *str)
{
	t_list	*list;
	char	*buf;
	int		nbr;

	buf = str;
	list = ft_create_elem('a', 0);
	while (*buf)
	{
		ft_if_c(&buf, &list);
		ft_if_d(&buf, &list);
		if (ft_ifchar(*buf) >= 0 && ft_ifchar(*buf) <= 5)
			ft_addtol(&list, *buf, 0);
		buf++;
	}
	if (list->prev->sbl != 'a')
		ft_if_o(&list);
	nbr = list->nbr;
	ft_delete(&list);
	free(list);
	return (nbr);
}
