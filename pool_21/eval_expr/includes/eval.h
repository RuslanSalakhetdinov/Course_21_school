/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:26:19 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/18 23:37:38 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_H
# define EVAL_H

# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	char			sbl;
	int				nbr;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

t_list				*ft_create_elem(char sbl, int nbr);
void				ft_delete(t_list **list);
t_list				*ft_add(t_list **add);
t_list				*ft_sub(t_list **sub);
t_list				*ft_mul(t_list **mul);
t_list				*ft_div(t_list **div);
t_list				*ft_mod(t_list **mod);
int					ft_atoi(char **str);
void				ft_putchar(char c);
void				ft_putnbr(int nbr);
int					eval_expr(char *str);
int					ft_ifchar(char c);

#endif
