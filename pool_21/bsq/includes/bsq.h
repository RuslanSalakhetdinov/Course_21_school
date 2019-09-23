/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knarwhal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 15:11:45 by knarwhal          #+#    #+#             */
/*   Updated: 2019/08/22 11:31:22 by knarwhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# define PSIZE 8
# include "stdlib.h"
# include "unistd.h"
# include <fcntl.h>

void	ft_bsq_if(int **arr, int **zero, int **params, int **v);
void	ft_bsq_solution(int **arr, int **zero, int **params);
void	ft_print_bsq(int **arr, int **elem, int **v, int **params);
void	ft_check_bsq_elem(int **arr, int **v, int **params);
void	ft_print_if(int **arr, int **elem, int **v, int **params);
void	printerror(int **params);
void	write2zero(int **zero, int **params, int **arr);
void	write2arr(int **arr, int **params, int fd);
void	createarr(int **params, int fd, char *av);
void	checkif(char *buf, char *flag, int **params, int *strcount);
void	checkparams(int **params, int fd, char *av);
void	init_params(char *arr, int fd, char *av);
int		ft_read_file(char *av);
void	ft_delete_zero(int **zero);
void	ft_clean(int **arr, int **elem, int **v, int **params);
int		ft_atoi(char **src, int **params);

#endif
