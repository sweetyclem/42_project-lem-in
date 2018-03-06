/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 08:51:33 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/06 14:47:35 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		search_graph(t_game *game)
{
	t_queue			*queue_list;
	t_room			*current;

	queue_list = new_queue();
	queue_list->room_name = ft_strdup(game->start);
	while (queue_list)
	{
		// ft_printf("\n");
		current = find_room(game, queue_list->room_name);
		queue_list = queue_list->next;
		if (ft_strcmp(current->name, game->end) == 0)
			return (1);
		if (!current->visited)
			current->visited = 1;
		// ft_printf("current : %s\n", current->name);
		queue_list = queue_connections(game, current->connections, queue_list);
		// t_queue *lst = queue_list;
		// while(lst)
		// {
		// 	ft_printf("queue : %s\n", lst->room_name);
		// 	lst = lst->next;
		// }
	}
	free(queue_list);
	return (0);
}

t_queue	*queue_connections(t_game *game, t_connect *connec, t_queue *queue_list)
{
	t_room			*tmp_room;
	t_queue			*queue_item;

	while (connec)
	{
		tmp_room = find_room(game, connec->name);
		if (!tmp_room->visited && !item_in_queue(queue_list, tmp_room->name))
		{
			queue_item = new_queue();
			queue_item->room_name = ft_strdup(tmp_room->name);
			queue_list = add_queue_end(queue_list, queue_item);
		}
		connec = connec->next;
	}
	return (queue_list);
}

void	find_path(t_game *game)
{
	t_room		*current_room;
	t_connect	*path;
	t_connect	*new_connect;
	char		*connected_name;

	path = NULL;
	current_room = find_room(game, game->end);
	while (ft_strcmp(connected_name, game->start) != 0)
	{
		connected_name = get_connected_visited(game, current_room->connections);
		if (!path)
		{
			path = new_connection();
			path->name = connected_name;
		}
		else
		{
			new_connect = new_connection();
			new_connect->name = connected_name;
			new_connect->next = path;
			path = new_connect;
		}
		current_room = find_room(game, connected_name);
	}
	while (path)
	{
		ft_printf("\npath item : %s\n", path->name);
		path = path->next;
	}
}

char	*get_connected_visited(t_game *game, t_connect *connections)
{
	t_room		*connected;

	while (connections)
	{
		connected = find_room(game, connections->name);
		ft_printf("connected to current : %s\n", connected->name);
		if (connected->visited)
			return (ft_strdup(connected->name));
		connections = connections->next;
	}
	return (NULL);
}