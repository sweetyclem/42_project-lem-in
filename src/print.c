/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 07:55:14 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/07 10:19:45 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_path(t_game *game)
{
	t_ant			*ants;
	t_connection	*path;
	t_room			*room;

	game->ants = create_game_ants(game);
	ants = game->ants;
	while (ants)
	{
		if (ants->arrived)
		{
			ants = ants->next;
			continue;
		}
		path = game->path;
		ft_printf("L%d", ants->nb);
		while (path)
		{
			room = find_room(game, path->name);
			ft_printf("-%s", path->name);
			path = path->next;
		}
		ft_putchar('\n');
		ants = ants->next;
	}
}

t_ant	*create_game_ants(t_game *game)
{
	t_ant	*list;
	t_ant	*item;
	int		i;

	i = game->nb_ants;
	while (i > 0)
	{
		item = new_ant();
		item->nb = i;
		item->step = game->path;
		item->arrived = 0;
		item->next = list;
		list = item;
		i--;
	}
	return (list);
}
