/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 08:51:33 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/07 10:19:05 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				search_graph(t_game *game)
{
	t_connection	*queue;
	t_connection	*tmp;
	t_room			*current;

	queue = new_connection();
	queue->name = ft_strdup(game->start);
	while (queue)
	{
		current = find_room(game, queue->name);
		tmp = queue;
		queue = queue->next;
		free(tmp->name);
		free(tmp);
		if (ft_strcmp(current->name, game->end) == 0)
		{
			free_connections(&queue);
			return (1);
		}
		if (!current->visited)
			current->visited = 1;
		queue = queue_connect(game, current, queue);
	}
	free(queue);
	return (0);
}

t_connection	*queue_connect(t_game *game, t_room *room, t_connection *queue)
{
	t_room			*connected;
	t_connection	*queue_item;
	t_connection	*connections;

	connections = room->connections;
	while (connections)
	{
		connected = find_room(game, connections->name);
		if (!connected->visited && !connection_in_list(queue, connected->name))
		{
			queue_item = new_connection();
			queue_item->name = ft_strdup(connected->name);
			connected->prev = ft_strdup(room->name);
			queue = add_connection_end(queue, queue_item);
		}
		connections = connections->next;
	}
	return (queue);
}

void			find_path(t_game *game)
{
	t_room			*current_room;
	t_connection	*connection;
	char			*connected_name;

	current_room = find_room(game, game->end);
	connected_name = NULL;
	game->path = NULL;
	connection = new_connection();
	connection->name = ft_strdup(game->end);
	game->path = add_connection(game->path, connection);
	while (ft_strcmp(connected_name, game->start) != 0)
	{
		if (connected_name)
			free(connected_name);
		connected_name = ft_strdup(current_room->prev);
		connection = new_connection();
		connection->name = ft_strdup(connected_name);
		if (ft_strcmp(connected_name, game->start) != 0)
			game->path = add_connection(game->path, connection);
		else
			free_connections(&connection);
		current_room = find_room(game, connected_name);
	}
	free(connected_name);
}
