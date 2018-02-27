/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:31:23 by cpirlot           #+#    #+#             */
/*   Updated: 2018/01/22 06:57:51 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_zero_flag(char *str, int minus)
{
	int		i;
	char	*before;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '0' && !minus)
		{
			before = ft_strndup(str, i);
			if (ft_str_multi_chr(before, "123456789") == NULL &&
			!ft_strchr(before, '.'))
			{
				free(before);
				return (1);
			}
			else
			{
				free(before);
				return (0);
			}
		}
		i++;
	}
	return (0);
}

int	get_plus_flag(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+')
			return (1);
		i++;
	}
	return (0);
}

int	get_minus_flag(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

int	get_pound_flag(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			return (1);
		i++;
	}
	return (0);
}

int	get_space_flag(char *str, int minus, int plus)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' && !minus && !plus)
			return (1);
		i++;
	}
	return (0);
}
