/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 20:15:01 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/06 10:28:03 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int forw_s;
	int forw_f;

	forw_s = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[forw_s] != '\0')
	{
		forw_f = 0;
		while (str[forw_s + forw_f] == to_find[forw_f])
		{
			if (to_find[forw_f + 1] == '\0')
				return (str + forw_s);
			forw_f++;
		}
		forw_s++;
	}
	return (0);
}
