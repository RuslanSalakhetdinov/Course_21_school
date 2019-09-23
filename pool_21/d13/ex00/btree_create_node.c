/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:49:52 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/17 18:37:38 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree *new_root;

	new_root = (t_btree*)malloc(sizeof(t_btree));
	if (new_root)
	{
		new_root->item = item;
		new_root->left = NULL;
		new_root->right = NULL;
	}
	return (new_root);
}
