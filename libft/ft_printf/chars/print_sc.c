/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 07:23:25 by cpirlot           #+#    #+#             */
/*   Updated: 2018/01/24 15:43:20 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_sc(va_list *va, t_format format)
{
	int		char_written;
	char	c;
	char	*str;

	char_written = 0;
	if (format.conversion == 'c')
	{
		c = (char)va_arg(*va, int);
		char_written += print_char(char_written, format, c);
	}
	else if (format.conversion == 's')
	{
		str = (char *)va_arg(*va, char *);
		char_written += print_string(char_written, format, str);
	}
	return (char_written);
}

int		print_string(int char_written, t_format format, char *str)
{
	int	prec;

	prec = format.precision;
	if (str || prec != 0)
	{
		if (prec == 0 && ft_strlen(str) > 0)
			char_written += (int)ft_strlen(str);
		else if (str && prec > 0 && prec < (int)ft_strlen(str))
			char_written += prec;
		else if (str && prec > 0)
			char_written += (int)ft_strlen(str);
		char_written += print_width(format, char_written);
		char_written += print_zero_padding(format, char_written);
		if (prec > 0)
			ft_putnstr(str, prec);
		else if (prec != -1)
			ft_putstr(str);
	}
	else
	{
		ft_putstr("(null)");
		char_written += 6;
	}
	char_written += print_width_minus(format, char_written);
	return (char_written);
}

int		print_char(int char_written, t_format format, char c)
{
	char_written += 1;
	char_written += print_width(format, char_written);
	char_written += print_zero_padding(format, char_written);
	ft_putchar(c);
	char_written += print_width_minus(format, char_written);
	return (char_written);
}

int		print_ptr(int char_written, va_list *va, t_format format)
{
	void	*ptr;
	int		p_len;
	int		prec;

	prec = 0;
	ptr = va_arg(*va, void *);
	p_len = ft_ptr_len_base((size_t)ptr, 16);
	if (!(format.precision == -1 && ptr == 0))
		char_written += p_len;
	char_written += 2;
	if (format.precision > 0)
		prec = format.precision - (ptr < 0 ? p_len - 1 : p_len);
	char_written += print_width(format, char_written + (prec > 0 ? prec : 0));
	ft_putstr("0x");
	char_written += print_zero_padding(format, char_written);
	char_written += print_precision(format, (int)ptr, p_len);
	if (!(format.precision == -1 && ptr == 0))
		ft_print_ptr((size_t)ptr);
	char_written += print_width_minus(format, char_written);
	return (char_written);
}

int		print_plain_char(int char_written, t_format format)
{
	char_written += 1;
	char_written += print_width(format, char_written);
	char_written += print_zero_padding(format, char_written);
	ft_putchar(format.conversion);
	char_written += print_width_minus(format, char_written);
	return (char_written);
}
