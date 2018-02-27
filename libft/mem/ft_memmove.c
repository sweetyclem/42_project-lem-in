/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:36:24 by cpirlot           #+#    #+#             */
/*   Updated: 2017/11/07 17:36:27 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*c_src;
	unsigned char	*c_dest;

	i = 0;
	c_src = (unsigned char *)src;
	c_dest = (unsigned char *)dest;
	if (c_dest < c_src)
	{
		while (i < n)
		{
			c_dest[i] = c_src[i];
			i++;
		}
	}
	else
	{
		i = n - 1;
		while ((int)i >= 0)
		{
			c_dest[i] = c_src[i];
			i--;
		}
	}
	return ((void *)c_dest);
}
