/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 08:13:27 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/07 15:41:38 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	read_input(t_game *game)
{
	char	*line;

	if (get_next_line(0, &line) == 0)
		ft_exit_error("ERROR: empty file\n");
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
		ft_exit_error("ERROR: missing start or end\n");
	if (!game->rooms)
		ft_exit_error("ERROR: no room\n");
	if (!game->rooms->connections)
		ft_exit_error("ERROR: no link\n");
}

void	get_ant_nb(char *line, t_game *game)
{
	int		ants;

	if (line == 0)
		ft_exit_error("ERROR: empty file\n");
	if (line[0] != '#')
	{
		if (!ft_isnumber(line))
			ft_exit_error("ERROR: missing ants number\n");
		ft_printf("%s\n", line);
		ants = ft_atoi(line);
		if (ants <= 0 || ants > 2147483647)
			ft_exit_error("ERROR: wrong ants number\n");
		game->nb_ants = ants;
	}
	else if (get_next_line(0, &line) > 0)
		get_ant_nb(line, game);
	// free(line);
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
		ft_exit_error("ERROR: empty line\n");
	ft_printf("%s\n", line);
	if (start && game->start)
		ft_exit_error("ERROR: duplicate start\n");
	if (end && game->end)
		ft_exit_error("ERROR: duplicate end\n");
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
		ft_exit_error("ERROR: wrong link line format\n");
	if (!room_exists(game, split[0]) || !room_exists(game, split[1]))
		ft_exit_error("ERROR: unknown room in link\n");
	save_connection(game, split[0], split[1]);
	save_connection(game, split[1], split[0]);
	free(split[0]);
	free(split[1]);
	free(split);
}
