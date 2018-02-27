/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 10:11:22 by cpirlot           #+#    #+#             */
/*   Updated: 2018/02/27 12:59:01 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*new_room(void)
{
	t_room	*room;

	if (!(room = malloc(sizeof(t_room) * 1)))
		return (NULL);
	room->name = NULL;
	room->x = -1;
	room->y = -1;
	room->next = NULL;
	return (room);
}

t_game	initialize_game(void)
{
	t_game	game;

	game.nb_ants = 0;
	game.start = NULL;
	game.end = NULL;
	game.rooms = new_room();
	return (game);
}

void	free_game(t_game *game)
{
	t_room	*tmp;

	tmp = game->rooms;
	free(game->start);
	free(game->end);
	while (game->rooms)
	{
		tmp = game->rooms;
		game->rooms = game->rooms->next;
		free(tmp->name);
		free(tmp);
	}
	free(game->rooms);
}

void	add_room_end(t_game *game, t_room *room)
{
	t_room	*tmp;
	tmp = game->rooms;
	while(tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = room;
	room->next = NULL;
}
