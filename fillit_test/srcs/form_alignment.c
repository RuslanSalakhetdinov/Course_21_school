/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_alignment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:55:56 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/02/20 20:37:30 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

t_form	*form_alignment(t_form *form)
{
	while (form->pos[0][0] != 0 && form->pos[1][0] != 0 && \
			form->pos[2][0] != 0 && form->pos[3][0] != 0)
	{
		form->pos[0][0]--;
		form->pos[1][0]--;
		form->pos[2][0]--;
		form->pos[3][0]--;
	}
	while (form->pos[0][1] != 0 && form->pos[1][1] != 0 && \
			form->pos[2][1] != 0 && form->pos[3][1] != 0)
	{
		form->pos[0][1]--;
		form->pos[1][1]--;
		form->pos[2][1]--;
		form->pos[3][1]--;
	}
		return (form);
}
