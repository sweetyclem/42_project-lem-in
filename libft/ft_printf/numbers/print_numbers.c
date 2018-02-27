/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 07:00:40 by cpirlot           #+#    #+#             */
/*   Updated: 2018/01/22 06:57:51 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_numbers(va_list *va, t_format format)
{
	int				char_written;
	char			c;

	char_written = 0;
	c = format.conversion;
	if (c == 'd' || c == 'i' || c == 'D')
		char_written += print_d(va, char_written, format);
	else if (c == 'u' || c == 'U')
		char_written += print_u(va, char_written, format);
	else if (c == 'o' || c == 'O')
		char_written += print_o(va, char_written, format);
	else if (c == 'x' || c == 'X')
		char_written += print_x(va, char_written, format);
	return (char_written);
}

int	print_d(va_list *va, int char_written, t_format format)
{
	char		c;
	long long	nb;

	c = format.conversion;
	if (c == 'd' || c == 'i' || c == 'D')
	{
		if (format.l == 1 || c == 'D')
			nb = (long long)va_arg(*va, long);
		else if (format.l == 2)
			nb = (long long)va_arg(*va, long long);
		else if (format.j == 1)
			nb = (intmax_t)va_arg(*va, intmax_t);
		else if (format.z == 1)
			nb = (size_t)va_arg(*va, size_t);
		else if (format.h == 1)
			nb = (short)va_arg(*va, int);
		else if (format.h == 2)
			nb = (char)va_arg(*va, int);
		else
			nb = (long long)va_arg(*va, int);
		char_written += print_d_longlong(char_written, format, nb);
	}
	return (char_written);
}

int	print_o(va_list *va, int char_written, t_format format)
{
	long long			nb;

	if (format.l || format.h || format.j || format.z ||
	format.conversion == 'O')
		char_written += print_o_unsigned(va, char_written, format);
	else
	{
		nb = (long long)va_arg(*va, unsigned int);
		char_written += print_o_longlong(char_written, format, nb);
	}
	return (char_written);
}

int	print_u(va_list *va, int char_written, t_format format)
{
	char				c;
	unsigned long long	nb;

	c = format.conversion;
	if (c == 'u' || c == 'U')
	{
		if (format.l == 1 || c == 'U')
			nb = (unsigned long long)va_arg(*va, unsigned long);
		else if (format.l == 2)
			nb = (unsigned long long)va_arg(*va, unsigned long long);
		else if (format.h == 1)
			nb = (unsigned short)va_arg(*va, unsigned int);
		else if (format.h == 2)
			nb = (unsigned char)va_arg(*va, unsigned int);
		else if (format.j == 1)
			nb = (uintmax_t)va_arg(*va, uintmax_t);
		else if (format.z == 1)
			nb = (size_t)va_arg(*va, size_t);
		else
			nb = (unsigned long long)va_arg(*va, unsigned int);
		char_written += print_u_longlong(char_written, format, nb);
	}
	return (char_written);
}

int	print_x(va_list *va, int char_written, t_format format)
{
	char				c;
	unsigned long long	nb;

	c = format.conversion;
	if (format.l == 1)
		nb = (unsigned long long)va_arg(*va, unsigned long);
	else if (format.l == 2)
		nb = (unsigned long long)va_arg(*va, unsigned long long);
	else if (format.h == 1)
		nb = (unsigned short)va_arg(*va, unsigned int);
	else if (format.h == 2)
		nb = (unsigned char)va_arg(*va, unsigned int);
	else if (format.j == 1)
		nb = (uintmax_t)va_arg(*va, uintmax_t);
	else if (format.z == 1)
		nb = (size_t)va_arg(*va, size_t);
	else
		nb = (unsigned long long)va_arg(*va, unsigned int);
	char_written += print_x_longlong(char_written, format, nb);
	return (char_written);
}
