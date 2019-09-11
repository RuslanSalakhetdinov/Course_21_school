/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:09:19 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/09/04 13:00:55 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strlen(char *str)
{
	char	*buff;
	int		num;

	buff = str;
	num = 0;
	if (!buff)
		return (0);
	while (*buff++)
		num++;
	return (num);
}
