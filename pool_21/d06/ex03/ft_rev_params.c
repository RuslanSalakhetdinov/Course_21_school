/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 19:04:45 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/07 22:54:07 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	char	*buffer;
	int		i;

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
