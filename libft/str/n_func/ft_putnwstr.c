/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 08:20:45 by cpirlot           #+#    #+#             */
/*   Updated: 2018/01/24 09:26:37 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnwstr(wchar_t *str, int len)
{
	int i;

	i = 0;
	while (len > 0 && str[i] != '\0')
	{
		if (ft_wcharlen(str[i]) > len)
			break ;
		else
			ft_putwchar(str[i]);
		i++;
		len -= ft_wcharlen(str[i]);
	}
}
