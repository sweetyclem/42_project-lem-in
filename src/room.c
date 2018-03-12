/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:07:28 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/12 10:50:45 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	get_room(char *line, t_game *game, int start, int end)
{
	char	**split;
	t_room	*room;

	room = new_room();
	if (game->rooms && !(game->rooms->connections == NULL))
		free_exit("ERROR: link before room\n", game);
	split = ft_strsplit(line, ' ');
	if (!split[0] || !split[1] || !split[2])
		free_exit("ERROR: wrong room line format\n", game);
	if (split[0][0] == 'L')
		free_exit("ERROR: room name can't start with an 'L'\n", game);
	if (room_exists(game, split[0]))
		free_exit("ERROR: duplicate room name\n", game);
	room->name = ft_strdup(split[0]);
	if (start && !game->start)
		game->start = ft_strdup(split[0]);
	if (end && !game->end)
		game->end = ft_strdup(split[0]);
	if (!ft_isnumber(split[1]) || !ft_isnumber(split[2])
	|| ft_atoi(split[1]) < 0 || ft_atoi(split[2]) < 0)
		free_exit("ERROR: wrong format for coordinates\n", game);
	room->next = NULL;
	add_room_end(game, room);
	ft_free_array(&split, 3);
}

int		room_exists(t_game *game, char *room)
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

t_room	*find_room(t_game *game, char *name)
{
	t_room	*tmp;

	tmp = game->rooms;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
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
