/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 08:33:38 by cpirlot           #+#    #+#             */
/*   Updated: 2018/01/24 09:23:37 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wstrnlen(wchar_t *str, int n)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if ((len + ft_wcharlen(str[i])) > n)
			break ;
		else
			len += ft_wcharlen(str[i]);
		i++;
	}
	return (len);
}
