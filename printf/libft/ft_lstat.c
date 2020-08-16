/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.21-shool.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:08:36 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/08/08 14:08:38 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list *lst, size_t val)
{
	size_t i;

	i = 0;
	while (i < val && lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}
