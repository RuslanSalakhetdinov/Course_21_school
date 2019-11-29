/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:50:29 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/11/29 15:10:46 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_form		*form_new(char **f, char type)
{
	t_form	*new;
	char	**buf;
	int		i;

	if (!(new = (t_form*)malloc(sizeof(*new))))
		return (NULL);
	if (!(buf = (char**)malloc(sizeof(*buf) * 5)))
		return (NULL);
	i = -1;
	while (++i < 5)
		buf[i] = ft_strdup(f[i]);
	new->type = type;
	new->link = NULL;
}
