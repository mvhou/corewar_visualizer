/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/04 17:35:27 by eutrodri      #+#    #+#                 */
/*   Updated: 2020/04/25 12:24:05 by eutienne      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../includes/libft.h"
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

/*
**EU_Hashtag (1 << 0)	// 1		0000 0000 0000 0001
**EU_Zero (1 << 1)		// 2		0000 0000 0000 0010
**EU_Plus (1 << 2)		// 4		0000 0000 0000 0100
**EU_Minus (1 << 3)		// 8		0000 0000 0000 1000
**EU_Space (1 << 4)		// 16		0000 0000 0001 0000
**EU_h (1 << 5)			// 32		0000 0000 0010 0000
**EU_hh (1 << 6)		// 64		0000 0000 0100 0000
**EU_l (1 << 7)			// 128		0000 0000 1000 0000
**EU_ll (1 << 8)		// 256		0000 0001 0000 0000
**EU_L (1 << 9)			// 512		0000 0010 0000 0000
**EU_Point (1 << 10)	// 1024		0000 0100 0000 0000
**EU_Floatminus(1 << 11)//2048		0000 1000 0000 0000
*/

enum
{
	EU_HA = (1 << 0),
	EU_Z = (1 << 1),
	EU_P = (1 << 2),
	EU_M = (1 << 3),
	EU_S = (1 << 4),
	EU_H = (1 << 5),
	EU_HH = (1 << 6),
	EU_EL = (1 << 7),
	EU_LL = (1 << 8),
	EU_L = (1 << 9),
	EU_PO = (1 << 10),
	EU_FM = (1 << 11)
};

/*
** # define EU_HA (1 << 0)
** # define EU_Z (1 << 1)
** # define EU_P (1 << 2)
** # define EU_M (1 << 3)
** # define EU_S (1 << 4)
** # define EU_H (1 << 5)
** # define EU_HH (1 << 6)
** # define EU_EL (1 << 7)
** # define EU_LL (1 << 8)
** # define EU_L (1 << 9)
** # define EU_PO (1 << 10)
** # define EU_FM (1 << 11)
*/

typedef	union		u_floats
{
	long double		floats;
	uint64_t		mantissa;
	uint16_t		exponent[5];

}					t_floats;

typedef struct		s_flags
{
	short int		option;
	char			specifier;
	int				width;
	int				percision;
	int				counter;

}					t_flags;

int					ft_printf(const char *restrict format, ...);

void				putnbr_base(unsigned long long value, int base, int l);

void				check_type(t_flags *checks, va_list args);
void				check_s_width_percision(t_flags *checks, long long x);
void				check_s_width_percision1\
						(t_flags *checks, int y, long long x);
void				check_s_width_percision2\
						(t_flags *checks, int y, long long x);
void				check_s_width_percision3\
						(t_flags *checks, int y, long long x);
void				check_s_width_percision4\
						(t_flags *checks, int y, long long x);
void				check_width_percision\
						(t_flags *checks, unsigned long long x);
void				check_width_percision1(t_flags *checks, int y);
void				check_width_percision2(t_flags *checks, int y);
void				check_width_percision3(t_flags *checks, int y);
void				check_width_percision4(t_flags *checks, int y);

void				handle_astrix(char **f, t_flags *checks, va_list a);
void				handle_arg(t_flags *checks, va_list args, char **f);
void				handle_zerops(t_flags *checks);
void				handle_zerop0s(t_flags *checks);
void				handle_zeros(t_flags *checks);
void				handle_zerop(t_flags *checks);
void				handle_zerop0(t_flags *checks);
void				handle_zero(t_flags *checks);
void				handle_floats(t_flags *checks, va_list args);

void				print_percision(int y, t_flags *checks);
void				print_width(int y, t_flags *checks);
void				print_percision_0(int y, t_flags *checks);
void				print_width_0(int y, t_flags *checks);
void				print_width_zero(int y, t_flags *checks);
void				print_and_check(char **f, va_list args, t_flags *checks);
void				print_unsigned_dec(t_flags *checks, unsigned long long x);
void				print_signed_dec(t_flags *checks, long long x);
void				print_pointer(unsigned long long int x, t_flags *checks);
void				print_str(char *x, t_flags *checks);
void				print_arg(t_flags *checks, va_list args);
void				print_char(char x, t_flags *checks);
void				print_strpers(char *x, t_flags *checks, int y);
void				print_plus_space(t_flags *checks);
void				print_neg(t_flags *checks);

void				store_flags(char **f, t_flags *checks, va_list args);
void				store_precision(char **f, t_flags *checks, va_list a);
void				store_width(char **f, t_flags *checks, va_list a);
void				store_decimal_flags(char **f, t_flags *checks);
void				store_specifier(char **f, t_flags *checks);
void				set_checks_0(t_flags *checks);

int					ifhash(int y, t_flags *checks);
int					ifhash1(int y, char c);
int					count_nbr(t_flags *checks, unsigned long long x);
int					count_s_nbr(long long x);
int					count_position(unsigned long long x, unsigned long long z);
int					check_validf(t_floats *floats, t_flags *checks);
int					get_float_in_string\
						(t_flags *c, t_floats *floats, char	*str);
int					get_flag_in_float(char *str, int num, t_flags *c);

long long			get_num_signed(va_list args, t_flags *checks);
unsigned long long	get_num_unsigned(va_list args, t_flags *checks);

#endif
