/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 12:42:38 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/01 22:08:03 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_alphabet(void)
{
	char symbol;

	symbol = 'a';
	while (symbol <= 'z')
	{
		ft_putchar(symbol);
		symbol++;
	}
}
