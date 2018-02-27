/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:20:00 by cpirlot           #+#    #+#             */
/*   Updated: 2017/11/07 17:29:02 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*bdest;
	unsigned char	*bsrc;
	size_t			i;

	bdest = (unsigned char *)dest;
	bsrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		bdest[i] = bsrc[i];
		if ((unsigned char)c == bsrc[i])
			return ((void*)&bdest[i + 1]);
		i++;
	}
	return (NULL);
}
