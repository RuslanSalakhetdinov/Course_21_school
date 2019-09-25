/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 20:01:47 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/09 14:32:36 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_if(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return(1);
	return(0);
}

int		ft_wordlen(char *str)
{
	int len;

	len = 0;
	while (ft_if(str) == 1)
		str++;
	while (ft_if(str) == 0)
	{
		if (*str)
			return (len);
		len++;
		str++;
	}
	return (len);
}

void	ft_wordcpy(char **strarr, char *str)
{
	int i;
	int j;
	while (ft_if(str) == 1)
		str++;
	while (ft_if(str) == 0)
	{
		if (*str)
			break;
		*strarr[i] = *str;
		str++;
		i++;
	}
}

char	**ft_split_whitespaces(char *str)
{
	char **strarr;
	char *buffer;
	char **bufarr;

	buffer = str;
	bufarr = strarr;
	while (*buffer)
	{
		*bufarr = (char*)malloc(sizeof(**strarr) * (ft_wordlen(buffer) + 1));
		*bufarr++;
	}
	*bufarr = "\0";
	buffer = str;
	bufarr = strarr;
	while (*buffer)
	{
		ft_wordcpy(*bufarr);
		bufarr++;
	}
	return (strarr);
}
