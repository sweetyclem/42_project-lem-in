/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 10:11:22 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/06 10:25:31 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*new_room(void)
{
	t_room	*room;

	if (!(room = malloc(sizeof(t_room) * 1)))
		return (NULL);
	room->name = NULL;
	room->connections = NULL;
	room->visited = 0;
	room->next = NULL;
	return (room);
}

t_connect	*new_connection(void)
{
	t_connect	*connection;

	if (!(connection = malloc(sizeof(t_connect) * 1)))
		return (NULL);
	connection->name = NULL;
	connection->next = NULL;
	return (connection);
}

t_queue			*new_queue(void)
{
	t_queue	*queue;

	if (!(queue = malloc(sizeof(t_queue) * 1)))
		return (NULL);
	queue->room_name = NULL;
	queue->next = NULL;
	return (queue);
}

t_game			initialize_game(void)
{
	t_game	game;

	game.nb_ants = -1;
	game.start = NULL;
	game.end = NULL;
	game.rooms = NULL;
	return (game);
}

void			free_game(t_game *game)
{
	t_room			*tmp_room;
	t_connect	*tmp_connection;

	free(game->start);
	free(game->end);
	while (game->rooms)
	{
		tmp_room = game->rooms;
		while (tmp_room->connections)
		{
			tmp_connection = tmp_room->connections;
			tmp_room->connections = tmp_room->connections->next;
			free(tmp_connection->name);
			free(tmp_connection);
		}
		free(tmp_room->connections);
		game->rooms = game->rooms->next;
		free(tmp_room->name);
		free(tmp_room);
	}
	free(game->rooms);
}
