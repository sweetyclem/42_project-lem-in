/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 09:16:39 by cpirlot           #+#    #+#             */
/*   Updated: 2018/01/24 09:45:56 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_longlong_d(long long nbr)
{
	unsigned long long nb;

	if (nbr < 0)
	{
		if (nbr != LONG_LONG_MIN)
			nbr *= -1;
	}
	nb = nbr;
	if (nb >= (unsigned long long)10)
		ft_put_longlong_d(nb / 10);
	ft_putchar(nb % 10 + '0');
}

int			print_d_longlong(int char_written, t_format format, long long nb)
{
	int	nb_len;

	nb_len = ft_longlong_len(nb);
	if (format.plus && nb >= 0)
		char_written += 1;
	char_written += print_space(format, nb);
	if (!(format.precision == -1 && nb == 0))
		char_written += nb_len;
	if (format.precision > 0 && format.precision > nb_len && nb >= 0)
		char_written += format.precision - nb_len;
	if (format.precision > 0 && format.precision == nb_len && nb < 0)
		char_written += format.precision - nb_len + 1;
	if (format.precision > 0 && format.precision > nb_len && nb < 0)
		char_written += format.precision - nb_len + 1;
	char_written += print_width(format, char_written);
	print_plus(format, nb);
	if (nb < 0)
		ft_putchar('-');
	char_written += print_zero_padding(format, char_written);
	print_precision(format, nb, nb_len);
	if (!(format.precision == -1 && nb == 0))
		ft_put_longlong_d(nb);
	char_written += print_width_minus(format, char_written);
	return (char_written);
}
