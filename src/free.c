/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 10:11:22 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/13 13:25:02 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	free_ants(&game->ants);
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

void			free_ants(t_ant **ants)
{
	t_ant	*tmp_ant;

	while (*ants)
	{
		tmp_ant = *ants;
		*ants = (*ants)->next;
		free(tmp_ant);
	}
	free(*ants);
}

int				free_exit(t_game *game)
{
	if (!game->nb_ants || !game->start || !game->end || !game->rooms
	|| !game->rooms->connections)
	{
		if (game)
			free_game(game);
		ft_printf("ERROR\n");
		exit(0);
	}
	else
		return (0);
}
