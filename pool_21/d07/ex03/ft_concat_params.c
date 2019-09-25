/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 04:34:30 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/08 23:41:05 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int e_num;

	e_num = 0;
	while (*str != '\0')
	{
		str++;
		e_num++;
	}
	return (e_num);
}

char	*ft_strcat(int res, char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	if (res == 0)
		dest[i + j] = '\0';
	else
	{
		dest[i + j] = '\n';
		dest[i + j + 1] = '\0';
	}
	return (dest);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		len;
	int		buffer;
	char	*str;

	if (argc == 1)
		return (0);
	len = argc;
	buffer = argc;
	while (--buffer > 0)
		len += ft_strlen(argv[buffer]);
	str = (char*)malloc(len * sizeof(*str));
	while (++buffer < argc - 1)
		str = ft_strcat(1, str, argv[buffer]);
	str = ft_strcat(0, str, argv[buffer]);
	return (str);
}
