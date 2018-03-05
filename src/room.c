/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:07:28 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/05 14:00:44 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	get_room(char *line, t_game *game, int start, int end)
{
	char	**split;
	t_room	*room;

	room = new_room();
	split = ft_strsplit(line, ' ');
	if (!split[0] || !split[1] || !split[2])
		ft_exit_error("ERROR: wrong room line format\n");
	if (split[0][0] == 'L')
		ft_exit_error("ERROR: room name can't start with an 'L'\n");
	room->name = ft_strdup(split[0]);
	if (start)
		game->start = ft_strdup(split[0]);
	if (end)
		game->end = ft_strdup(split[0]);
	if (!ft_isnumber(split[1]) || !ft_isnumber(split[2])
	|| ft_atoi(split[1]) < 0 || ft_atoi(split[2]) < 0)
		ft_exit_error("ERROR: wrong format for coordinates\n");
	room->next = NULL;
	add_room_end(game, room);
	free(split[0]);
	free(split[1]);
	free(split[2]);
	free(split);
}

int		duplicate_room_name(t_game *game)
{
	t_room	*tmp;

	if (game->rooms == NULL)
		return (0);
	tmp = game->rooms;
	while (tmp && tmp->next)
	{
		if (ft_strcmp(tmp->name, tmp->next->name) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		room_exists(t_game	*game, char	*room)
{
	t_room	*tmp;

	if (game->rooms == NULL)
		return (0);
	tmp = game->rooms;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, room) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	add_room_end(t_game *game, t_room *room)
{
	t_room	*tmp;

	if (game->rooms == NULL)
	{
		game->rooms = room;
		return ;
	}
	tmp = game->rooms;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = room;
	room->next = NULL;
}
