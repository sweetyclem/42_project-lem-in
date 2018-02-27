/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_multi_chr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 07:26:36 by cpirlot           #+#    #+#             */
/*   Updated: 2018/01/15 08:30:43 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_multi_chr(char *str, char *characters)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (characters[j] != '\0')
		{
			if (str[i] == characters[j])
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
