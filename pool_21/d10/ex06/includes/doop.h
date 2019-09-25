/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:28:05 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/13 21:17:24 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOP_H
# define DOOP_H

# include <unistd.h>

long long	ft_add(int a, int b);
long long	ft_sub(int a, int b);
long long	ft_div(int a, int b);
long long	ft_mod(int a, int b);
long long	ft_mul(int a, int b);
int			ft_valid(int argc, char **argv);
int			ft_atoi(char *str);
void		ft_putnbr(int nbr);
void		ft_putchar(char c);
int			ft_eval(int nbr);

#endif
