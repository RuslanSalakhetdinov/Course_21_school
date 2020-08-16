/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwheatgr <cwheatgr@student.21-shool.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 13:42:12 by cwheatgr          #+#    #+#             */
/*   Updated: 2020/08/16 13:43:09 by cwheatgr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define HH 1
# define H 2
# define L 3
# define LL 5
# define ZEROS 0
# define START 1
# define END 2
# define MAX(x, y) x > y ? x : y

typedef struct			s_prf
{
	char				hash_flag;
	char				zero_flag;
	char				minus_flag;
	char				plus_flag;
	char				space_flag;
	char				is_neg;
	char				prepend;
	int					width;
	char				precision_flag;
	int					precision;
	char				is_nan;
	char				is_inf;
	char				modifier;
	int					type;
	char				valid;
}						t_prf;

int						ft_printf(const char *format, ...);
int						get_handler(t_prf *prf, va_list ap);

/*
** Parse Handlers
*/

int						prf_parser(const char *s, t_prf *prf, va_list ap);
int						parse_modifier(const char *s, t_prf *prf);
const char				*parse_flag(const char *s, t_prf *prf);
const char				*parse_width(const char *s, t_prf *prf, va_list ap);
int						handle_star_width(t_prf *prf, va_list ap,
	int star_flag);
const char				*parse_precision(const char *s, t_prf *prf, va_list ap);
const char				*parse_type(const char *s, t_prf *prf);

/*
** Coversion Handlers
*/
int						handle_c(t_prf *prf, va_list ap);
int						handle_s(t_prf *prf, va_list ap);
int						handle_p(t_prf *prf, va_list ap);
int						handle_d(t_prf *prf, va_list ap);
int						handle_u(t_prf *prf, va_list ap);
int						handle_o(t_prf *prf, va_list ap);
int						handle_x(t_prf *prf, va_list ap);
int						handle_f(t_prf *prf, va_list ap);
int						handle_percent(t_prf *prf);
void					text_write(const char **s, int *pos);

/*
** Handler utilities
*/
long long int			signed_handle_mod(t_prf *prf, va_list ap);
unsigned long long int	unsigned_handle_mod(t_prf *prf, va_list ap);
int						write_unsigned(t_prf *prf, unsigned long long n,
	char *s, char *prepend);
long double				float_handle_mod(t_prf *prf, va_list ap);
int						count_big_f(long double f);
long double				pf_atof_helper(char *s);
char					*big_f(long double f);
char					*little_f(long double f, int p, char *big_f);
void					pad_prf_f(int len, t_prf *prf, int seg);
int						prf_len_f(char *big_s, t_prf *prf);
char					set_sign_f(long double f, t_prf *prf);
void					flag_manager_f(long double f, t_prf *prf);
void					flag_helper_f_nan(t_prf *prf);
int						write_f(t_prf *prf, char sign, char *big_s,
	char *little_s);
void					free_helper_f(t_prf *prf, char *big_s,
	char *little_s);
long double				ten_pow(int pow);
int						is_even_str(char *str);
long double				ft_round(long double f, t_prf *prf);
int						is_signed_conv(int c);
void					flag_manager(t_prf *prf);
void					pad_prf(t_prf *prf, int len, int b_len, int seg);
int						prf_len(t_prf *prf, int len, char *prepend);
char					set_sign(long long int n, t_prf *prf);

/*
** Utilities
*/
void					write_padding(int len, char c);
char					*pf_dtoa_signed(long long int n);
int						places(unsigned long long n, int base);
char					*pf_dtoa_u(unsigned long long int n, int base, char c);
int						is_nan(long double f);
int						is_inf(long double f);
int						is_not_even_str(char *str);

#endif
