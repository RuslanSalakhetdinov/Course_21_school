/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beyond_borders.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:01:42 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/02/10 16:08:17 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		beyond_borders(t_form *form, int b_size, int flag)
{
	if (flag == 0)
	{
		if (form->pos[0][0] + form->x_base < b_size && \
				form->pos[1][0] + form->x_base < b_size && \
				form->pos[2][0] + form->x_base < b_size && \
				form->pos[3][0] + form->x_base < b_size)
			return (1);
		else
			return (0);
	}
	else
	{
		if (form->pos[0][1] + form->y_base < b_size && \
				form->pos[1][1] + form->y_base < b_size && \
				form->pos[2][1] + form->y_base < b_size && \
				form->pos[3][1] + form->y_base < b_size)
			return (1);
		else
			return (0);
	}
