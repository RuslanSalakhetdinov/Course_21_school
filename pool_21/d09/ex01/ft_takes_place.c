/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 17:37:21 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/08 18:17:25 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_am(int hour)
{
	if (hour >= 0 && hour < 11)
	{
		if (hour == 0)
		{
			hour += 12;
			printf("%d.00 A.M. AND %d.00 A.M.\n", hour, hour - 11);
		}
		else
			printf("%d.00 A.M. AND %d.00 A.M.\n", hour, hour + 1);
	}
}

void	ft_pm(int hour)
{
	if (hour >= 12 && hour < 23)
	{
		if (hour != 12)
		{
			hour -= 12;
			printf("%d.00 P.M. AND %d.00 P.M.\n", hour, hour + 1);
		}
		else
			printf("%d.00 P.M. AND %d.00 P.M.\n", hour, hour - 11);
	}
}

void	ft_takes_place(int hour)
{
	printf("THE FOOLLOWING TAKES PLACE BETWEEN ");
	ft_am(hour);
	ft_pm(hour);
	if (hour == 11)
		printf("%d.00 A.M. AND %d.00 P.M.\n", hour, hour + 1);
	if (hour == 23)
	{
		hour -= 12;
		printf("%d.00 P.M. AND %d.00 A.M.\n", hour, hour + 1);
	}
}
