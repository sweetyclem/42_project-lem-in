/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 08:51:33 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/06 13:44:25 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		solve(t_game *game)
{
	t_queue			*queue_list;
	t_room			*current;

	queue_list = new_queue();
	queue_list->room_name = ft_strdup(game->start);
	while (queue_list)
	{
		current = find_room(game, queue_list->room_name);
		queue_list = queue_list->next;
		if (ft_strcmp(current->name, game->end) == 0)
			return (1);
		if (!current->visited)
			current->visited = 1;
		queue_list = queue_connections(game, current->connections, queue_list);
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
		if (!tmp_room->visited)
		{
			queue_item = new_queue();
			queue_item->room_name = ft_strdup(tmp_room->name);
			queue_list = add_queue_end(queue_list, queue_item);
		}
		connec = connec->next;
	}
	return (queue_list);
}
