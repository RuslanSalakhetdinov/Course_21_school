/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 21:55:11 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/15 22:17:45 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int		btree_level_count(t_btree *root)
{
	int l_count;
	int r_count;

	if (!root)
		return (NULL);
	l_count = btree_level_count(root->left);
	h_count = btree_level_count(root->right);
	return (MAX(l_count + 1, r_count + 1));
}
