/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:06:43 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/07 07:41:20 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *str)
{
	long long		res;
	int				sign;
	char			*s;

	sign = 1;
	res = 0;
	s = (char *)str;
	s = ft_skip_whitespace(s);
	if (*s == '-' && s++)
		sign = -1;
	else if (*s == '+' && sign != -1)
		s++;
	while (*s >= '0' && *s <= '9')
	{
		res *= 10;
		res += (*s++ - '0');
	}
	return (res * sign);
}
