/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 22:24:49 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/04 22:26:22 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_first(int pos_x, int pos_y, int x, int y)
{
	if (y == pos_y && x == 1)
		ft_putchar('/');
	if (y == pos_y && x == pos_x && pos_x != 1)
		ft_putchar('\\');
	if (y == pos_y && x < pos_x && x > 1)
		ft_putchar('*');
	if (x == pos_x + 1)
		ft_putchar('\n');
}

void	ft_if(int pos_x, int pos_y, int x, int y)
{
	if (x == 1 && y == 1)
		ft_putchar('\\');
	if (x == pos_x && y == 1 && pos_x != 1)
		ft_putchar('/');
	if ((y == 1 || y == pos_y) && x > 1 && x < pos_x)
		ft_putchar('*');
	if ((x == 1 || x == pos_x) && y > 1 && y < pos_y)
		ft_putchar('*');
	if (x > 1 && x < pos_x && y > 1 && y < pos_y)
		ft_putchar(' ');
	if (x == pos_x + 1)
		ft_putchar('\n');
}

void	rush(int pos_x, int pos_y)
{
	int x;
	int y;

	y = pos_y;
	x = 0;
	if (y > 0 && pos_x > 0)
		while (++x <= pos_x + 1)
			ft_first(pos_x, pos_y, x, y);
	while (--y >= 1)
	{
		if (pos_x > 0)
		{
			x = 0;
			while (++x <= pos_x + 1)
				ft_if(pos_x, pos_y, x, y);
		}
	}
}
