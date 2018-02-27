/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:21:53 by cpirlot           #+#    #+#             */
/*   Updated: 2017/11/13 17:00:16 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	d;

	d = (char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == d)
			return ((char*)&s[i]);
		i--;
	}
	return (NULL);
}
