/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 13:10:42 by cpirlot           #+#    #+#             */
/*   Updated: 2018/01/24 11:24:04 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_space(t_format format, int nb)
{
	if (format.space && ft_strchr("diD", format.conversion))
	{
		if (nb >= 0)
		{
			ft_putchar(' ');
			return (1);
		}
	}
	return (0);
}

int	print_pound(t_format format, int nb)
{
	char	c;

	c = format.conversion;
	if (format.pound && ft_strchr("oO", c) && nb != 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (format.pound && ft_strchr("oO", c) && format.precision && nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
	else if (format.pound && c == 'x' && nb != 0)
	{
		ft_putstr("0x");
		return (2);
	}
	else if (format.pound && c == 'X' && nb != 0)
	{
		ft_putstr("0X");
		return (2);
	}
	return (0);
}

int	pound_length(t_format format, int nb)
{
	if (format.pound && ft_strchr("oO", format.conversion) && nb != 0)
		return (1);
	else if (format.pound && format.conversion == 'x' && nb != 0)
		return (2);
	else if (format.pound && format.conversion == 'X' && nb != 0)
		return (2);
	return (0);
}

int	print_plus(t_format format, int nb)
{
	if (format.plus && nb >= 0 && !ft_strchr("uU", format.conversion))
	{
		ft_putchar('+');
		return (1);
	}
	return (0);
}
