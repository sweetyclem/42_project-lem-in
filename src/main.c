/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 08:00:47 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/05 15:50:17 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	get_parents(t_game *game)
{
	t_room	*room;
	char	*current;
	char	*connected;

	connected = ft_strnew(1);
	current = find_connected_room(game, game->start);
	room = find_room(game, current);
	room->parent = ft_strdup(game->start);
	ft_printf("salle : %s\n", current);
	while (ft_strcmp(connected, game->end) != 0)
	{
		connected = find_connected_room(game, current);
		ft_printf("connected : %s\n", connected);
		room = find_room(game, connected);
		room->parent = ft_strdup(current);
		current = ft_strdup(connected);
	}
	room = find_room(game, game->end);
	room->parent = ft_strdup(connected);
	free(connected);
	free(current);
}

char	*find_connected_room(t_game *game, char *name)
{
	t_pipe	*tmp;
	t_room	*room;

	tmp = game->pipes;
	room = find_room(game, name);
	while(tmp)
	{
		if (ft_strcmp(tmp->room1, name) == 0
		&& ft_strcmp(tmp->room2, room->parent) != 0)
		{
			return (ft_strdup(tmp->room2));
		}
		if (ft_strcmp(tmp->room2, name) == 0
		&& ft_strcmp(tmp->room1, room->parent) != 0)
		{
			return (ft_strdup(tmp->room1));
		}
		tmp = tmp->next;
	}
	return (NULL);
}

int	main(void)
{
	t_game	game;

	game = initialize_game();
	read_input(&game);
	get_parents(&game);
	free_game(&game);
	return (0);
}
