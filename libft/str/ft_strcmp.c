/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 07:29:48 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/05 15:26:39 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i] != '\0' && (unsigned char)s1[i] == (unsigned char)s2[i])
		{
			i++;
		}
		return (unsigned char)s1[i] - (unsigned char)s2[i];
	}
	return (1);
}
