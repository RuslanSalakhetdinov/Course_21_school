/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 17:58:13 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/07 21:43:28 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	char *buffer;

	buffer = argv[argc - argc];
	while (*buffer != '\0')
	{
		ft_putchar(*buffer);
		buffer++;
	}
	ft_putchar('\n');
	return (0);
}
