/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:38:12 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/16 20:34:01 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item, \
		int (*cmpf)(void *, void *))
{
	t_btree *new_root;

	new_root = *root;
	while (new_root)
	{
		if (cmpf(item, new_root->item) >= 0)
			new_root = new_root->right;
		else
			new_root = new_root->left;
	}
	new_root = btree_create_node(item);
}
