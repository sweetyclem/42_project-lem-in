/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 10:11:22 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/06 16:49:48 by cpirlot          ###   ########.fr       */
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
	return (game);
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
		free(tmp_room);
	}
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
