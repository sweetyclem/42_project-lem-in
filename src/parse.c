/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 08:13:27 by cpirlot           #+#    #+#             */
/*   Updated: 2018/02/27 15:55:12 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	read_input(t_game *game)
{
	char	*line;

	get_next_line(0, &line);
	if (!ft_isnumber(line))
		ft_exit_error("ERROR : missing ants number\n");
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
	if (!game->start || !game->end)
		ft_exit_error("ERROR : missing start or end\n");
	if (!game->rooms)
		ft_exit_error("ERROR : no rooms\n");
}

int		is_comment(char *str)
{
	if (str[0] == '#' && str[1] != '#')
		return (1);
	return (0);
}

void	get_room_info(char *line, t_game *game)
{
	char	**split;
	t_room	*room;

	room = new_room();
	split = ft_strsplit(line, ' ');
	if (!split[0] || !split[1] || !split[2])
		ft_exit_error("ERROR: wrong line format\n");
	if (split[0][0] == 'L')
		ft_exit_error("ERROR : room name can't start with an 'L'\n");
	room->name = ft_strdup(split[0]);
	if (!ft_isnumber(split[1]) || !ft_isnumber(split[2]))
		ft_exit_error("ERROR: wrong format for coordinates\n");
	room->next = NULL;
	add_room_end(game, room);
	free(split[0]);
	free(split[1]);
	free(split[2]);
	free(split);
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
			get_room_info(str, game);
		}
		else
		{
			get_next_line(0, &str);
			ft_printf("%s\n", str);
			game->end = ft_strsub(str, 0, (ft_strchr(str, ' ') - str));
			get_room_info(str, game);
		}
		free(str);
	}
	else if (!ft_strchr(line, '-'))
		get_room_info(line, game);
}
