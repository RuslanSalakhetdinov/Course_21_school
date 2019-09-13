/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:41:26 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/13 16:55:53 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_count_words(int *count, char *c)
{
	int		mark;

	mark = 0;
	while (*s)
	{
		if (*s != (*c) && mark != 1)
		{
			(*count)++;
			mark++;
		}
		if (*s == (*c) && mark == 1)
			mark--;
		s++;
	}
}

static void	*ft_del_arr(char **arr, int index)
{
	int i;

	i = -1;
	while (++i < index)
		free(arr[i]);
}

static char	*ft_len_word(char *str, int *len)
{
	
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		count;
	int		i;
	int		len;

	count = 0;
	ft_count_words(&count, &c);
	arr = (char*)malloc(sizeof(*arr) * (count + 1));
	i = -1;
	while (++i < count)
	{
		len = 0;
		buf = ft_len_word(&len, buf)
	}
}

