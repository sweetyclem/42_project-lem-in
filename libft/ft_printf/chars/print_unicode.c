/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 06:55:37 by cpirlot           #+#    #+#             */
/*   Updated: 2018/01/24 17:15:23 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_unicode(va_list *va, t_format format)
{
	int		char_written;
	wchar_t	c;
	wchar_t	*s;

	char_written = 0;
	if (format.conversion == 'C' || format.conversion == 'c')
	{
		c = (wchar_t)va_arg(*va, wint_t);
		char_written += print_unicode_char(char_written, format, c);
	}
	else if (format.conversion == 'S' || format.conversion == 's')
	{
		s = (wchar_t *)va_arg(*va, wchar_t *);
		char_written += print_unicode_string(char_written, format, s);
	}
	return (char_written);
}

int		print_unicode_char(int char_written, t_format format, wchar_t c)
{
	int	prec;

	prec = format.precision;
	if (c == 0)
	{
		ft_putchar('\0');
		char_written += 0;
	}
	if ((c >= 55296 && c < 57344) || c < 0)
		return (-1);
	char_written += ft_wcharlen(c);
	char_written += print_width(format, char_written);
	char_written += print_zero_padding(format, char_written);
	ft_putwchar(c);
	char_written += print_width_minus(format, char_written);
	return (char_written);
}

int		print_unicode_string(int char_written, t_format format, wchar_t *s)
{
	int		prec;
	int		len;

	prec = format.precision;
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	len = ft_wstrlen(s);
	if (prec == 0)
		char_written += len;
	else if (prec > 0)
		char_written += ft_wstrnlen(s, prec);
	char_written += print_width(format, char_written);
	char_written += print_zero_padding(format, char_written);
	if (prec > 0)
		ft_putnwstr(s, ft_wstrnlen(s, prec));
	else if (prec != -1)
		ft_putwstr(s);
	char_written += print_width_minus(format, char_written);
	return (char_written);
}
