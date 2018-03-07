/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 07:55:14 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/07 15:49:52 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		nb_rooms_on_path(t_connection *path)
{
	t_connection	*list;
	int				result;

	list = path;
	result = 0;
	while (list)
	{
		list = list->next;
		result++;
	}
	return (result);
}

void	print_path(t_game *game)
{
	int		nb_steps;
	t_ant	*ants;

	nb_steps = nb_rooms_on_path(game->path) - 1 + game->nb_ants;
	game->ants = create_game_ants(game);
	game->ants->started = 1;
	while (nb_steps > 0)
	{
		move_ants(game, game->ants);
		ants = find_started(game->ants);
		if (ants->next)
			ants->next->started = 1;
		ft_printf("\n");
		nb_steps--;
	}
}

t_ant	*create_game_ants(t_game *game)
{
	t_ant	*list;
	t_ant	*item;
	int		i;

	list = NULL;
	i = game->nb_ants;
	while (i > 0)
	{
		item = new_ant();
		item->nb = i;
		item->step = game->path;
		item->started = 0;
		item->arrived = 0;
		item->next = list;
		list = item;
		i--;
	}
	return (list);
}

t_ant	*find_started(t_ant *lst)
{
	t_ant	*ants;

	ants = lst;
	while (ants->next && ants->next->started)
		ants = ants->next;
	return (ants);
}

void	move_ants(t_game *game, t_ant *ants)
{
	t_room	*room;

	while (ants)
	{
		if (ants->started)
		{
			if (ants->arrived)
			{
				ants = ants->next;
				continue;
			}
			ft_printf("L%d", ants->nb);
			room = find_room(game, ants->step->name);
			ft_printf("-%s", ants->step->name);
			ants->step = ants->step->next;
			if (ants->step == NULL)
				ants->arrived = 1;
			ft_printf(" ");
		}
		ants = ants->next;
	}
}
