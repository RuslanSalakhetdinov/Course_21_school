/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:36:06 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/14 14:52:18 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	char	*buffer;
	int		i;

	i = 1;
	while (i < argc)
	{
		buffer = argv[i];
		while (*buffer != '\0')
		{
			ft_putchar(*buffer);
			buffer++;
		}
		ft_putchar('\n');
		i++;
	}
}
