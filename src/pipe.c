/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:07:17 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/06 10:26:24 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	get_pipe(char *line, t_game *game)
{
	char			**split;
	t_room			*room;

	split = ft_strsplit(line, '-');
	if (!split[0] || !split[1])
		ft_exit_error("ERROR: wrong pipe line format\n");
	if (!room_exists(game, split[0]) || !room_exists(game, split[1]))
		ft_exit_error("ERROR: unknown room in pipe\n");
	room = find_room(game, split[0]);
	add_connection_end(room, ft_strdup(split[1]));
	room = find_room(game, split[1]);
	add_connection_end(room, ft_strdup(split[0]));
	free(split[0]);
	free(split[1]);
	free(split);
}

void	add_connection_end(t_room *room, char *connection_name)
{
	t_connect	*tmp;
	t_connect	*new;

	new = new_connection();
	new->name = connection_name;
	new->next = NULL;
	if (room->connections == NULL)
	{
		room->connections = new;
		return ;
	}
	tmp = room->connections;
	while (tmp->next != NULL)
	{
		if (ft_strcmp(tmp->name, connection_name) == 0)
			ft_exit_error("ERROR: duplicate pipe\n");
		tmp = tmp->next;
	}
	tmp->next = new;
}
