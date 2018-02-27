/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_whitespace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:25:53 by cpirlot           #+#    #+#             */
/*   Updated: 2017/11/13 16:26:44 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_skip_whitespace(const char *str)
{
	const char	*s;

	s = str;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	return (s);
}
