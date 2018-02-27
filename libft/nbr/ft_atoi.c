/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:06:43 by cpirlot           #+#    #+#             */
/*   Updated: 2017/11/13 17:06:32 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *str)
{
	unsigned int	res;
	int				sign;
	int				max;
	const char		*s;

	sign = 1;
	res = 0;
	max = 0;
	s = ft_skip_whitespace(str);
	if (*s == '-' && s++)
		sign = -1;
	else if (*s == '+' && sign != -1)
		s++;
	while (*s >= '0' && *s <= '9')
	{
		res *= 10;
		res += (*s++ - '0');
		max++;
	}
	if (max > 18 && sign == 1)
		return (-1);
	if (max > 18 && sign == -1)
		return (0);
	return (res * sign);
}
