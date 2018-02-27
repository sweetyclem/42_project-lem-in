/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 09:22:28 by cpirlot           #+#    #+#             */
/*   Updated: 2018/01/22 06:57:51 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_o_unsigned(va_list *va, int char_written, t_format format)
{
	unsigned long long	u_nb;

	u_nb = 0;
	if (format.l == 1 || format.conversion == 'O')
		u_nb = (unsigned long long)va_arg(*va, unsigned long);
	else if (format.l == 2)
		u_nb = (unsigned long long)va_arg(*va, unsigned long long);
	else if (format.h == 1)
		u_nb = (unsigned short)va_arg(*va, unsigned int);
	else if (format.h == 2)
		u_nb = (unsigned char)va_arg(*va, unsigned int);
	else if (format.j == 1)
		u_nb = (uintmax_t)va_arg(*va, uintmax_t);
	else if (format.z == 1)
		u_nb = (size_t)va_arg(*va, size_t);
	char_written += print_u_o_longlong(char_written, format, u_nb);
	return (char_written);
}

int	print_o_longlong(int char_written, t_format format, long long nb)
{
	int	prec;
	int	nb_len;

	prec = 0;
	nb_len = ft_len_base(nb, 8);
	if (format.precision != -1 || nb != 0 || format.pound)
		char_written += nb_len;
	if (format.precision > 0)
		prec = format.precision - (nb < 0 ? nb_len - 1 : nb_len);
	if (format.pound && nb != 0)
	{
		format.precision -= 1;
		char_written += 1;
	}
	char_written += print_width(format, char_written + (prec > 0 ? prec : 0));
	print_pound(format, nb);
	char_written += print_zero_padding(format, char_written);
	char_written += print_precision(format, nb, nb_len);
	if (format.precision != -1 || nb != 0)
		ft_put_longlong_base(nb, 8);
	char_written += print_width_minus(format, char_written);
	return (char_written);
}

int	print_u_o_longlong(int char_written, t_format format, unsigned long long nb)
{
	int	prec;
	int	nb_len;

	prec = 0;
	nb_len = ft_u_len_base(nb, 8);
	if (!(format.precision == -1 && nb == 0))
		char_written += nb_len;
	char_written += print_pound(format, nb);
	if (format.precision > 0)
		prec = format.precision - nb_len;
	char_written += print_width(format, char_written + (prec > 0 ? prec : 0));
	char_written += print_zero_padding(format, char_written);
	char_written += print_precision(format, nb, nb_len);
	if (!(format.precision == -1 && nb == 0))
		ft_put_u_longlong_base(nb, 8);
	char_written += print_width_minus(format, char_written);
	return (char_written);
}
