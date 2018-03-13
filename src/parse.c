/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 08:13:27 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/13 15:40:01 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	read_input(t_game *game)
{
	char	*line;

	if (get_next_line(0, &line) == 0)
		exit_incomplete_game(game);
	get_ant_nb(line, game);
	free(line);
	while (get_next_line(0, &line) > 0 && ft_strlen(line) > 0)
	{
		ft_printf("%s\n", line);
		if (!(line[0] == '#' && line[1] != '#'))
		{
			if (!parse_line(line, game))
				return ;
		}
		free(line);
	}
	if (line)
		free(line);
	if (!game->start || !game->end || !game->rooms || !game->rooms->connections)
		exit_incomplete_game(game);
}

void	get_ant_nb(char *line, t_game *game)
{
	int		ants;

	if (line == 0)
		exit_incomplete_game(game);
	if (line[0] != '#')
	{
		if (!ft_isnumber(line))
			exit_incomplete_game(game);
		ft_printf("%s\n", line);
		ants = ft_atoi(line);
		if (ants <= 0 || ants > 2147483647)
			exit_incomplete_game(game);
		game->nb_ants = ants;
	}
	else if (get_next_line(0, &line) > 0)
		get_ant_nb(line, game);
}

int		parse_line(char *line, t_game *game)
{
	int ret;

	ret = 1;
	if (line[0] == '#' && line[1] == '#')
	{
		if (ft_strcmp(&line[2], "start") == 0)
			get_start_or_end(game, 1, 0);
		else if (ft_strcmp(&line[2], "end") == 0)
			get_start_or_end(game, 0, 1);
	}
	else if (!ft_strchr(line, '-'))
		ret = get_room(line, game, 0, 0);
	else if (ft_strchr(line, '-'))
		ret = get_link(line, game);
	return (ret);
}

void	get_start_or_end(t_game *game, int start, int end)
{
	char	*line;

	get_next_line(0, &line);
	if (ft_strlen(line) == 0 || (start && game->start) || (end && game->end))
		exit_incomplete_game(game);
	ft_printf("%s\n", line);
	if (line[0] != '#')
		get_room(line, game, start, end);
	else
		get_start_or_end(game, start, end);
	free(line);
}

int		get_link(char *line, t_game *game)
{
	char			**split;

	split = ft_strsplit(line, '-');
	if (!split[0] || !split[1] || !room_exists(game, split[0])
	|| !room_exists(game, split[1]))
	{
		if (!exit_incomplete_game(game))
			return (0);
	}
	save_connection(game, split[0], split[1]);
	save_connection(game, split[1], split[0]);
	ft_free_array(&split);
	return (1);
}
