/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:32:49 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/02/10 14:37:41 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		form_count(t_form *form)
{
int		count;

	count = 0;
	while (form)
	{
		form = form->next;
		count++;
	}
	return (count);
}
