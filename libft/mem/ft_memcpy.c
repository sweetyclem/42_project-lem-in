/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 07:14:51 by cpirlot           #+#    #+#             */
/*   Updated: 2017/11/08 07:18:13 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*bdest;
	char	*bsrc;

	i = 0;
	bdest = (char *)dest;
	bsrc = (char *)src;
	while (i < n)
	{
		bdest[i] = bsrc[i];
		i++;
	}
	return (bdest);
}
