/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:22:09 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/06 16:55:51 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_if(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

char	ft_chrupcase(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

char	ft_chrlowcase(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	if (str[0] == '\0')
		return (str);
	else
		str[0] = ft_chrupcase(str[0]);
	i = 1;
	while (str[i] != '\0')
	{
		if (ft_if(str[i - 1]) == 0)
			str[i] = ft_chrupcase(str[i]);
		else
			str[i] = ft_chrlowcase(str[i]);
		i++;
	}
	return (str);
}
