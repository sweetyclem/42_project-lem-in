/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 08:13:27 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/05 13:13:05 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	read_input(t_game *game)
{
	char	*line;

	if (get_next_line(0, &line) == 0 || ft_strlen(line) == 0)
		ft_exit_error("ERROR: empty file\n");
	game->nb_ants = get_ant_nb(line);
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
		ft_exit_error("ERROR: no rooms\n");
	if (check_double_room_name(game) != 1)
		ft_exit_error("ERROR: double room name\n");
}

int		get_ant_nb(char *line)
{
	int	ants;

	if (!ft_isnumber(line))
		ft_exit_error("ERROR: missing ants number\n");
	ft_printf("%s\n", line);
	ants = ft_atoi(line);
	if (ants <= 0 || ants > 2147483647)
		ft_exit_error("ERROR: wrong ants number\n");
	return (ants);
}

void	parse_line(char *line, t_game *game)
{
	if (line[0] == '#' && line[1] == '#')
	{
		if (ft_strcmp(&line[2], "start") == 0)
		{
			get_next_line(0, &line);
			if (ft_strlen(line) > 0)
			{
				ft_printf("%s\n", line);
				get_room(line, game, 1, 0);
				free(line);
			}
		}
		else if (ft_strcmp(&line[2], "end") == 0)
		{
			get_next_line(0, &line);
			if (ft_strlen(line) > 0)
			{
				ft_printf("%s\n", line);
				get_room(line, game, 0, 1);
			}
			free(line);
		}
	}
	else if (!ft_strchr(line, '-'))
		get_room(line, game, 0, 0);
	else if (ft_strchr(line, '-'))
		get_pipe(line, game, 0, 0);
}
