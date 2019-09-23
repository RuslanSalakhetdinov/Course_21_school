/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:47:14 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/23 19:08:28 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_count(char *s, char c, int *count)
{
	char	mark;

	mark = '0';
	while (*s)
	{
		if (*s != c && mark == '0')
		{
			(*count)++;
			mark = '1';
		}
		if (*s == c && mark == '1')
			mark = '0';
		s++;
	}
}

static void	ft_del_arr(char **arr, int index)
{
	int i;

	i = -1;
	while (++i < (index - 1))
		free(arr[i]);
	free(arr);
}

static void	ft_set_word(char **arr, char **s, char c, int index)
{
	int		len;
	char	*buf;

	buf = (*s);
	while (*buf == c)
		buf++;
	(*s) = buf;
	len = 0;
	while (*buf != c)
	{
		len++;
		buf++;
	}
	arr[index] = (char*)malloc(sizeof(*(*arr)) * (len + 1));
	if (!arr[index])
		ft_del_arr(arr, index);
	len = 0;
	while (*(*s) != c)
	{
		arr[len][index] = *(*s);
		len++;
		(*s)++;
	}
	arr[len][index] = '\0';
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		count;
	int		index;

	count = 0;
	ft_count(&(char*)*s, c, &count);
	arr = (char**)malloc(sizeof(*arr) * (count + 1));
	index = -1;
	while (++index < count)
	{
		ft_set_word(arr, &s, c, index);
		if (!arr)
			return (NULL);
	}
	arr[0][index] = '\0';
	return (arr);
}
