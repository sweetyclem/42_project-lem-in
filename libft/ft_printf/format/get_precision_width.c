/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision_width.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:40:24 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/07 07:51:41 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_width(char *str)
{
	int		i;
	int		j;
	char	*tmp;
	char	*before;
	int		width;

	i = 0;
	j = 0;
	width = 0;
	tmp = ft_strnew(ft_strlen(str));
	while (str[i] != '\0')
	{
		before = ft_strndup(str, i);
		if (ft_strchr("0123456789", str[i]) && !ft_strchr(before, '.'))
		{
			tmp[j] = str[i];
			j++;
		}
		free(before);
		i++;
	}
	width = ft_atoi(tmp);
	free(tmp);
	return (width);
}

int	get_precision(char *str)
{
	int		i;
	int		res;
	char	*tmp;

	i = 0;
	res = 0;
	tmp = ft_strnew(ft_strlen(str));
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			ft_memset(tmp, '\0', ft_strlen(str));
			i++;
			while (ft_strchr("0123456789", str[i]) && str[i] != '\0')
				*tmp++ = str[i++];
		}
		else
			i++;
	}
	if (ft_strchr(str, '.') && (ft_strcmp(tmp, "0") == 0 || tmp[0] == '\0'))
		return (-1);
	res = ft_atoi(tmp);
	free(tmp);
	return (res);
}
