/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 07:31:48 by cpirlot           #+#    #+#             */
/*   Updated: 2017/11/08 07:32:51 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*dest;

	dest = ft_strnew(n);
	if (dest)
	{
		dest = ft_strncpy(dest, str, n);
		return (dest);
	}
	else
		return (NULL);
}
