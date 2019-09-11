/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:52:16 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/04 16:45:23 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar(char c);

void		ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int			ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void		ft_sort_arg(int ac, char **av)
{
	int		i;
	char	*buff;

	i = 0;
	while (++i < ac - 1)
		while (ft_strcmp(av[i], av[i + 1]) > 0)
		{
			buff = av[i];
			av[i] = av[i + 1];
			av[i + 1] = buff;
			i = 0;
		}
}

int			main(int ac, char **av)
{
	int		i;

	if (ac == 1)
		return (0);
	ft_sort_arg(ac, av);
	i = 0;
	while (++i < ac)
	{
		ft_putstr(av[i]);
		ft_putchar('\n');
	}
}
