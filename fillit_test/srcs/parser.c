/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 22:19:46 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/02/24 22:52:12 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

char		*get_tetramino(int fd, char *tetraminoshka)
{
	int		i;
	char	*temp;

	i = 0;
	ft_strclr(tetraminoshka);
	while (i < 4)
	{
		if (get_next_line(fd, &temp) < 1)
			return (NULL);
		temp[4] = 'q';
		temp[5] = '\0';
		ft_strcat(tetraminoshka, temp);
		ft_strclr(temp);
		i++;
		free(temp);
	}
	if (get_next_line(fd, &temp))
		free(temp);
	return (tetraminoshka);
}

int			get_tetraminos_form(int fd, char symbol)
{
	char	*temp;
	char	*tetraminoshka;
	t_form	*head;
	t_form	*buf;
	t_form	*buf2;

	tetraminoshka = (char *)malloc(sizeof(char) * 20);
	symbol = 'A';
	if (!(temp = get_tetramino(fd, tetraminoshka)))
		return (-1);
	if (is_it_tetra(temp) == 0)
		return (-1);
	head = form_new(temp, symbol);
	buf2 = head;
	while ((temp = get_tetramino(fd, tetraminoshka)) != NULL)
	{
		if (is_it_tetra(temp) == 0 && temp)
			return (-1);
		buf = form_new(temp, ++symbol);
		buf2->next = buf;
		buf2 = buf;
	}
	free(tetraminoshka);
	solution(head);
	return (1);
}
