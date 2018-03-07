/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 10:11:22 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/07 08:09:16 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_game			initialize_game(void)
{
	t_game	game;

	game.nb_ants = -1;
	game.start = NULL;
	game.end = NULL;
	game.rooms = NULL;
	game.path = NULL;
	return (game);
}

t_connection	*new_connection(void)
{
	t_connection	*connection;

	if (!(connection = malloc(sizeof(t_connection) * 1)))
		return (NULL);
	connection->name = NULL;
	connection->next = NULL;
	return (connection);
}

void			free_game(t_game *game)
{
	t_room			*tmp_room;

	free(game->start);
	free(game->end);
	while (game->rooms)
	{
		tmp_room = game->rooms;
		free_connections(&tmp_room->connections);
		game->rooms = game->rooms->next;
		free(tmp_room->name);
		free(tmp_room->prev);
		free(tmp_room);
	}
	free_connections(&game->path);
	free(game->rooms);
}

void			free_connections(t_connection **connections)
{
	t_connection	*tmp_connection;

	while (*connections)
	{
		tmp_connection = *connections;
		*connections = (*connections)->next;
		free(tmp_connection->name);
		free(tmp_connection);
	}
	free(*connections);
}
