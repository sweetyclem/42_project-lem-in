/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 09:06:41 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/07 10:18:31 by cpirlot          ###   ########.fr       */
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
	game.ants = NULL;
	return (game);
}

t_room			*new_room(void)
{
	t_room	*room;

	if (!(room = malloc(sizeof(t_room) * 1)))
		return (NULL);
	room->name = NULL;
	room->connections = NULL;
	room->visited = 0;
	room->prev = NULL;
	room->next = NULL;
	return (room);
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

t_ant			*new_ant(void)
{
	t_ant	*ant;

	if (!(ant = malloc(sizeof(t_ant) * 1)))
		return (NULL);
	ant->step = NULL;
	ant->nb = 0;
	ant->arrived = 0;
	ant->next = NULL;
	return (ant);
}
