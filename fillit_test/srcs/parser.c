/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 01:02:53 by lgunship          #+#    #+#             */
/*   Updated: 2020/02/19 14:34:21 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

char	*get_tetramino(int fd, char *tetraminoshka)
{
	int		i;
	char	*temp;

	i = 0;
	ft_strclr(tetraminoshka);
	while (i < 4)
	{
		if(get_next_line(fd, &temp) < 1)
			return (NULL);
		temp[4] = 'q';
		temp[5] = '\0';
		ft_strcat(tetraminoshka, temp);
		ft_strclr(temp);
		i++;
		free(temp);
	}
	get_next_line(fd, &temp);
	free (temp);
	return (tetraminoshka);
}

int get_tetraminos_form (int fd)
{
	char	simbol;
	char	*temp;
	char	*tetraminoshka;
	t_form	*head;
	t_form	*buf;
	t_form	*buf2;

	tetraminoshka = (char *)malloc(sizeof(char) * 20);
	simbol = 'A';
	temp = get_tetramino(fd, tetraminoshka);
	if (is_it_tetra(temp) == 0)
		return (-1);
	head = form_new(temp, simbol);
	buf2 = head;
	while ((temp = get_tetramino(fd, tetraminoshka)) != NULL)
	{
		if (is_it_tetra(temp) == 0 && temp)
			return (-1);
		buf = form_new(temp, ++simbol);
		buf2->next = buf;
		buf2 = buf;
	}
	free(tetraminoshka);
	solution(head);
	return (1);
}
