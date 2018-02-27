/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 10:17:10 by cpirlot           #+#    #+#             */
/*   Updated: 2018/01/09 09:07:25 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_ptr(size_t nb)
{
	char *str;

	str = "0123456789abcdef";
	if (nb < 16)
		ft_putchar(str[nb]);
	else
	{
		ft_print_ptr(nb / 16);
		ft_putchar(str[nb % 16]);
	}
}
