/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:56:17 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/02/12 17:15:42 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_form		*form_new(int row, int col)
{
	t_form	*buf;

	if (!row || !col)
		return (NULL);
	if (!(buf = (t_form*)malloc(sizeof(t_form))))
		return (NULL);
	buf->row = row;
	buf->col = col;
	buf->zoom = NULL;
	buf->mlx_ptr = NULL;
	buf->win_ptr = NULL;
	//allocate deapth by file_board
}