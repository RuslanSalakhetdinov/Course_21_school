/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 15:04:20 by exam              #+#    #+#             */
/*   Updated: 2019/08/16 15:34:51 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_str(char *str)
{
	char *buf;
	int marker;

	buf = str;
	while (*buf)
	{
		if (*buf != ' ' && *buf != '\t')
		{
			write(1, buf, 1);
			marker = 1;
		}
		else
		{
			if (marker == 1)
				write(1, "   ", 3);
			marker = 0;
		}
		buf++;
	}
	write(1, "\n", 1);
}

char	*begin_str(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}

char	*end_str(char *s)
{
	char *str;

	str = s;
	while (*str)
		str++;
	str --;
	while (*str == ' ' || *str == '\t')
	{
		*str = '\0';
		str--;
	}
	return (s);
}

int		main(int argc, char **argv)
{
	char *buf;
	if (argc != 2)
		write(1, "\n", 1);
	else if (!argv[1][0])
		write(1, "\n", 1);
	else
	{
		buf = argv[1];
		buf = begin_str(buf);
		buf = end_str(buf);
		print_str(buf);
	}
	return (0);
}
