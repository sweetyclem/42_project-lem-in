/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 07:36:25 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/07 07:22:27 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*sub_to_n(char *str)
{
	int		i;

	i = 0;
	while (str != '\0' && str[i] != '\n')
		i++;
	str = ft_strsub(str, 0, i);
	return (str);
}

static char	*sub_from_n(char *str)
{
	int		i;
	char	*s;

	i = 0;
	while (str != '\0' && str[i] != '\n')
		i++;
	s = ft_strsub(str, i + 1, ft_strlen(str));
	free(str);
	return (s);
}

static char	*join_and_free(char *str, char *buff)
{
	char	*tmp;

	tmp = ft_strjoin(str, buff);
	free(str);
	return (tmp);
}

int			get_next_line(int const fd, char **line)
{
	int				char_read;
	char			buff[BUFF_SIZE + 1];
	static char		*str[OPEN_MAX];

	char_read = 0;
	if (fd < 0 || fd > OPEN_MAX || !line)
		return (-1);
	if (str[fd] == NULL)
		str[fd] = ft_strnew(BUFF_SIZE);
	while (!ft_strchr(str[fd], '\n') &&
	(char_read = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[char_read] = '\0';
		str[fd] = join_and_free(str[fd], buff);
	}
	if (char_read == -1)
		return (-1);
	*line = (ft_strchr(str[fd], '\n') ? sub_to_n(str[fd]) : ft_strdup(str[fd]));
	if (ft_strchr((str[fd]), '\n'))
		str[fd] = sub_from_n(str[fd]);
	else
		ft_strdel(&str[fd]);
	if (str[fd] == NULL && ft_strlen(*line) == 0)
		return (0);
	return (1);
}
