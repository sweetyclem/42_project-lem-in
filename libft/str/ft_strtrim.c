/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:31:47 by cpirlot           #+#    #+#             */
/*   Updated: 2017/11/14 11:32:04 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(const char *s)
{
	const char	*temp;

	if (!s)
		return (NULL);
	while (ft_is_space(*s))
		s++;
	if (!*s)
		return (ft_strdup(""));
	temp = ft_strchr(s, '\0') - 1;
	while (ft_is_space(*temp))
		temp--;
	return (ft_strsub(s, 0, temp - s + 1));
}
