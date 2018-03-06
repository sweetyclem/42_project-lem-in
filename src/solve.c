/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 08:51:33 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/06 16:37:39 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		search_graph(t_game *game)
{
	t_connection	*queue;
	t_room			*current;

	queue = new_connection();
	queue->name = ft_strdup(game->start);
	while (queue)
	{
		ft_printf("\n");
		current = find_room(game, queue->name);
		queue = queue->next;
		if (ft_strcmp(current->name, game->end) == 0)
		{
			free_connections(&queue);
			return (1);
		}
		if (!current->visited)
			current->visited = 1;
		ft_printf("current : %s\n", current->name);
		queue = queue_connections(game, current->connections, queue);
		t_connection *lst = queue;
		while(lst)
		{
			ft_printf("queue : %s\n", lst->name);
			lst = lst->next;
		}
	}
	free_connections(&queue);
	return (0);
}

t_connection	*queue_connections(t_game *game, t_connection *connections,
t_connection *queue)
{
	t_room			*tmp_room;
	t_connection	*queue_item;

	while (connections)
	{
		tmp_room = find_room(game, connections->name);
		if (!tmp_room->visited && !connection_in_list(queue, tmp_room->name))
		{
			queue_item = new_connection();
			queue_item->name = ft_strdup(tmp_room->name);
			queue = add_connection_end(queue, queue_item);
		}
		connections = connections->next;
	}
	return (queue);
}

void	find_path(t_game *game)
{
	t_room		*current_room;
	t_connection	*path;
	t_connection	*new_connect;
	char		*connected_name;

	path = NULL;
	current_room = find_room(game, game->end);
	while (ft_strcmp(connected_name, game->start) != 0)
	{
		free(connected_name);
		connected_name = connection_visited(game, current_room->connections);
		if (!path)
		{
			path = new_connection();
			path->name = ft_strdup(connected_name);
		}
		else
		{
			new_connect = new_connection();
			new_connect->name = ft_strdup(connected_name);
			new_connect->next = path;
			path = new_connect;
		}
		current_room = find_room(game, connected_name);
	}

	t_connection	*tmp = path;
	while (tmp)
	{
		ft_printf("\npath item : %s\n", tmp->name);
		tmp = tmp->next;
	}
	free(connected_name);
	free_connections(&path);
}

char	*connection_visited(t_game *game, t_connection *connections)
{
	t_room		*connected;

	while (connections)
	{
		connected = find_room(game, connections->name);
		if (connected->visited)
			return (ft_strdup(connected->name));
		connections = connections->next;
	}
	return (NULL);
}