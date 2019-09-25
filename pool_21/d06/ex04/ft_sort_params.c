/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 19:15:25 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/07 22:04:06 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sort(int ac, char **av)
{
	int		i;
	char	*buffer;

	i = 1;
	while (i < ac - 1)
	{
		while (ft_strcmp(av[i], av[i + 1]) < 0)
		{
			buffer = av[i];
			av[i] = av[i + 1];
			av[i + 1] = buffer;
			i = 1;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	char	*buffer;
	int		i;

	ft_sort(argc, argv);
	i = argc - 1;
	while (i > 0)
	{
		buffer = argv[i];
		while (*buffer != '\0')
		{
			ft_putchar(*buffer);
			buffer++;
		}
		ft_putchar('\n');
		i--;
	}
}
