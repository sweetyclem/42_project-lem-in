/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:07:26 by cpirlot           #+#    #+#             */
/*   Updated: 2017/11/07 16:40:47 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *pointer, size_t length)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char*)pointer;
	while (length--)
	{
		p[i] = 0;
		i++;
	}
}
