/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 08:13:27 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/12 10:55:31 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	read_input(t_game *game)
{
	char	*line;

	if (get_next_line(0, &line) == 0)
		free_exit("ERROR: empty file\n", game);
	get_ant_nb(line, game);
	free(line);
	while (get_next_line(0, &line) > 0 && ft_strlen(line) > 0)
	{
		ft_printf("%s\n", line);
		if (!(line[0] == '#' && line[1] != '#'))
			parse_line(line, game);
		free(line);
	}
	if (line)
		free(line);
	if (!game->start || !game->end)
		free_exit("ERROR: missing start or end\n", game);
	if (!game->rooms)
		free_exit("ERROR: no room\n", game);
	if (!game->rooms->connections)
		free_exit("ERROR: no link\n", game);
}

void	get_ant_nb(char *line, t_game *game)
{
	int		ants;

	if (line == 0)
		free_exit("ERROR: empty file\n", game);
	if (line[0] != '#')
	{
		if (!ft_isnumber(line))
			free_exit("ERROR: missing ants number\n", game);
		ft_printf("%s\n", line);
		ants = ft_atoi(line);
		if (ants <= 0 || ants > 2147483647)
			free_exit("ERROR: wrong ants number\n", game);
		game->nb_ants = ants;
	}
	else if (get_next_line(0, &line) > 0)
		get_ant_nb(line, game);
}

void	parse_line(char *line, t_game *game)
{
	if (line[0] == '#' && line[1] == '#')
	{
		if (ft_strcmp(&line[2], "start") == 0)
			get_start_or_end(game, 1, 0);
		else if (ft_strcmp(&line[2], "end") == 0)
			get_start_or_end(game, 0, 1);
	}
	else if (!ft_strchr(line, '-'))
		get_room(line, game, 0, 0);
	else if (ft_strchr(line, '-'))
		get_link(line, game);
}

void	get_start_or_end(t_game *game, int start, int end)
{
	char	*line;

	get_next_line(0, &line);
	if (ft_strlen(line) == 0)
		free_exit("ERROR: empty line\n", game);
	ft_printf("%s\n", line);
	if (start && game->start)
		free_exit("ERROR: duplicate start\n", game);
	if (end && game->end)
		free_exit("ERROR: duplicate end\n", game);
	if (line[0] != '#')
		get_room(line, game, start, end);
	else
		get_start_or_end(game, start, end);
	free(line);
}

void	get_link(char *line, t_game *game)
{
	char			**split;

	split = ft_strsplit(line, '-');
	if (!split[0] || !split[1])
		free_exit("ERROR: wrong link line format\n", game);
	if (!room_exists(game, split[0]) || !room_exists(game, split[1]))
		free_exit("ERROR: unknown room in link\n", game);
	save_connection(game, split[0], split[1]);
	save_connection(game, split[1], split[0]);
	free(split[0]);
	free(split[1]);
	free(split);
}
