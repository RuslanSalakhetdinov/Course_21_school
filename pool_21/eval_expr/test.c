/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 20:42:19 by cwheatgr          #+#    #+#             */
/*   Updated: 2019/08/18 20:42:32 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

nclude <stdlib.h>
# include <unistd.h>

typedef struct    r_list
{
	char            sbl;
	int                nbr;
	struct r_list    *next;
	struct r_list    *prev;
}                t_list;

t_list *ft_create_elem(char sbl, int nbr)
{
	    t_list *new_list;

		    new_list = (t_list*)malloc(sizeof(t_list));
			    if (new_list)
					    {
							        new_list->sbl = sbl;
									        new_list->nbr = nbr;;
											        new_list->next = NULL;
													        new_list->prev = NULL;
															    }
				    return (new_list);
}

void    ft_delete(t_list **list)
{
	    t_list *buf;
		    t_list *arr;

			    arr = *list;
				    if (arr)
						    {
								        if (arr->prev)
											        {
														            buf = arr;
																	            arr = arr->prev;
																				            *list = arr;
																							            arr->next = NULL;
																										            free(buf);
																													        }
										        else
													            free(arr);
												    }
}

int        ft_ifchar(char c)
{
	    if (c == '+')
			        return (0);
		    if (c == '-')
				        return (1);
			    if (c == '/')
					        return (2);
				    if (c == '%')
						        return (3);
					    if (c == '*')
							        return (4);
						    if (c == '(')
								        return (5);
							    if (c == ')')
									        return (6);
								    if (c >= '0' && c <= '9')
										        return (7);
									    return (-42);
}

t_list    *ft_add(t_list **b_add)
{
	    t_list *add;

		    add = *b_add;
			    add->prev->nbr += add->next->nbr;
				    add = add->next;
					    ft_delete(&add);
						    ft_delete(&add);
							    *b_add = add;
								    return (add);
}



int            ft_atoi(char **src)
{
	    int        nb;
		    int        suff;
			    char    *str;

				    str = *src;
					    nb = 0;
						    suff = 1;
							    while (*str == '\0' || *str == '\n' || *str == '\t' || *str == '\v'
										            || *str == '\f' || *str == '\r' || *str == ' ')
									        str++;
								    if (*str == '-')
										    {
												        str += 1;
														        suff *= -1;
																    }
									    if (*str == '+')
											        str += 1;
										    while (*str != '\0' && *str >= '0' && *str <= '9')
												    {
														        nb = (*str - '0') + 10 * nb;
																        str += 1;
																		    }
											    str--;
												    *src = str;
													    return (nb *= suff);
}

void        ft_addtol(t_list **list, char sbl, int nbr)
{
	    t_list *p;
		    t_list *n;

			    n = *list;
				    while (n->next)
						        n = n->next;
					    p = n;
						    n = ft_create_elem(sbl, nbr);
							    n->prev = p;
								    p->next = n;
									    *list = n;
}

void        ft_if_c(char **buf, t_list **list)
{
	    if (**buf == ')')
			    {
					        while ((*list)->sbl != '(')
								        {
											            *list = (*list)->prev;
														            if ((*list)->sbl == '+')
																		                *list = ft_add(list);
																	        }
							        (*list)->nbr = (*list)->next->nbr;
									        (*list)->sbl = '\0';
											        *list = (*list)->next;
													        ft_delete(list);
															    }
}

void        ft_if_d(char **buf, t_list **list)
{
	    if (**buf >= '0' && **buf <= '9')
			    {
					        ft_addtol(list, '\0', ft_atoi(buf));
							    }
}


int            eval_expr(char *str)
{
	    t_list    *list;
		    char    *buf;
			    int        nbr;

				    buf = str;
					    list = ft_create_elem('\0', 0);
						    while (*buf)
								    {
										        ft_if_c(&buf, &list);
												        ft_if_d(&buf, &list);
														        if (ft_ifchar(*buf) >= 0 && ft_ifchar(*buf) <= 5)
																	            ft_addtol(&list, *buf, 0);
																        buf++;
																		    }
							    nbr = list->nbr;
								    ft_delete(&list);
									    free(list);
										    return (nbr);
}

int        main(void)
{
	    char *str = "(2 + 3)";
		  
		    eval_expr(str);
			    return (0);
}
