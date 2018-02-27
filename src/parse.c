/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 08:13:27 by cpirlot           #+#    #+#             */
/*   Updated: 2018/02/27 11:11:55 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	read_input(t_game *game)
{
	char	*line;

	get_next_line(0, &line);
	ft_printf("%s\n", line);
	if (!ft_isnumber(line))
		ft_exit_error("ERROR\n");
	game->nb_ants = ft_atoi(line);
	free(line);
	while (get_next_line(0, &line) > 0)
	{
		ft_printf("%s\n", line);
		if (!is_comment(line))
			parse_line(line, game);
		free(line);
	}
	if (line)
		free(line);
}

int		is_comment(char *str)
{
	if (str[0] == '#' && str[1] != '#')
		return (1);
	return (0);
}

void	parse_line(char *line, t_game *game)
{
	int		i;
	char	*str;

	i = 0;
	if (line[0] == '#' && line[1] == '#')
	{
		if (ft_strcmp(&line[2], "start") == 0)
		{
			get_next_line(0, &str);
			ft_printf("%s\n", str);
			game->start = ft_strsub(str, 0, (ft_strchr(str, ' ') - str));
		}
		else
		{
			get_next_line(0, &str);
			ft_printf("%s\n", str);
			game->end = ft_strsub(str, 0, (ft_strchr(str, ' ') - str));
		}
		free(str);
	}
}
