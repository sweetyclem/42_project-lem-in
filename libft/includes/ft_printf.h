/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:24:23 by cpirlot           #+#    #+#             */
/*   Updated: 2018/01/30 08:30:05 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include "struct.h"
# include <stdarg.h>
# include <limits.h>
# include <stdlib.h>
# include <wchar.h>

int			ft_printf(const char *format, ...);
int			parse_format(va_list *va, char *format);

/*
** Args
*/
int			parse_args(va_list *va, char **str);
int			dispatch_conversion(va_list *va, char **str, t_format format);
char		*handle_format(char *str, t_format *format);
t_format	save_format(char *str, int i);

/*
** Format saving
*/
int			get_width(char *str);
int			get_precision(char *str);
int			get_zero_flag(char *str, int minus);
int			get_plus_flag(char *str);
int			get_minus_flag(char *str);
int			get_pound_flag(char *str);
int			get_space_flag(char *str, int minus, int plus);
int			get_length(char *str, char c);

/*
** Printing for flags
*/
int			print_space(t_format format, int nb);
int			print_pound(t_format format, int nb);
int			pound_length(t_format format, int nb);
int			print_plus(t_format format, int nb);
int			print_width(t_format format, int char_written);
int			print_width_minus(t_format format, int char_written);
int			print_zero_padding(t_format format, int char_written);
int			print_precision(t_format format, int nb, int nb_len);

/*
** Printing for conversions d i D u U
*/
int			print_numbers(va_list *va, t_format format);
int			print_d(va_list *va, int char_written, t_format format);
int			print_d_longlong(int char_written, t_format format, long long nb);
int			print_u(va_list *va, int char_written, t_format format);
int			print_u_longlong(int char_written, t_format format,
unsigned long long nb);

/*
** Printing for conversions o O x X
*/
int			print_o(va_list *va, int char_written, t_format format);
int			print_o_unsigned(va_list *va, int char_written, t_format format);
int			print_o_longlong(int char_written, t_format format, long long nb);
int			print_u_o_longlong(int char_written, t_format format,
unsigned long long nb);
int			print_x(va_list *va, int char_written, t_format format);
int			print_x_longlong(int char_written, t_format format,
unsigned long long nb);

/*
** Printing for strings and chars
*/
int			print_sc(va_list *va, t_format format);
int			print_char(int char_written, t_format format, char c);
int			print_string(int char_written, t_format format, char *str);
int			print_ptr(int char_written, va_list *va, t_format format);
int			print_plain_char(int char_written, t_format format);
int			print_unicode(va_list *va, t_format format);
int			print_unicode_char(int char_written, t_format format, wchar_t c);
int			print_unicode_string(int char_written, t_format format, wchar_t *s);
#endif
