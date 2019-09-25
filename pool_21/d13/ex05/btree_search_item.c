/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 20:47:20 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/16 21:19:43 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref, \
		int (*cmpf)(void *, void *))
{
	if (root->left)
		btree_search_item(root->left, data_ref, cmpf);
	if (root)
		if (!cmpf(root->item, data_ref))
			return (root);
	if (root->right)
		btree_search_item(root->right, data_ref, cmpf);
	return (NULL);
}
