/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 10:11:22 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/05 14:33:23 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*new_room(void)
{
	t_room	*room;

	if (!(room = malloc(sizeof(t_room) * 1)))
		return (NULL);
	room->name = NULL;
	room->parent = NULL;
	room->next = NULL;
	return (room);
}

t_pipe	*new_pipe(void)
{
	t_pipe	*pipe;

	if (!(pipe = malloc(sizeof(t_pipe) * 1)))
		return (NULL);
	pipe->room1 = NULL;
	pipe->room2 = NULL;
	pipe->next = NULL;
	return (pipe);
}

t_game	initialize_game(void)
{
	t_game	game;

	game.nb_ants = -1;
	game.start = NULL;
	game.end = NULL;
	game.rooms = NULL;
	game.pipes = NULL;
	return (game);
}

void	free_game(t_game *game)
{
	t_room	*tmp_room;
	t_pipe	*tmp_pipe;

	free(game->start);
	free(game->end);
	while (game->rooms)
	{
		tmp_room = game->rooms;
		game->rooms = game->rooms->next;
		free(tmp_room->name);
		free(tmp_room->parent);
		free(tmp_room);
	}
	free(game->rooms);
	while (game->pipes)
	{
		tmp_pipe = game->pipes;
		game->pipes = game->pipes->next;
		free(tmp_pipe->room1);
		free(tmp_pipe->room2);
		free(tmp_pipe);
	}
	free(game->pipes);
}
