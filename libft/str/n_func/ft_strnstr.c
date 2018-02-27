/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:21:18 by cpirlot           #+#    #+#             */
/*   Updated: 2017/11/08 17:15:33 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len2;
	size_t	ibis;

	if (ft_strlen(s1) == 0)
		return (NULL);
	i = 0;
	len2 = len;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0' && i < len2)
	{
		j = 0;
		ibis = i;
		while (i < len2 && s1[i++] == s2[j++])
		{
			if (s2[j] == '\0')
				return (char *)s1 + (i - ft_strlen(s2));
		}
		i = ibis;
		i++;
		len--;
	}
	return (NULL);
}
