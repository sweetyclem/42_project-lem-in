/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 13:10:11 by cpirlot           #+#    #+#             */
/*   Updated: 2018/02/27 15:16:22 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_missing_info(t_game *game)
{
	t_room	*tmp;

	if (game->nb_ants <= 0)
		ft_exit_error("ERROR : missing ants number\n");
	if (!game->start || !game->end)
		ft_exit_error("ERROR : missing start or end\n");
	if (!game->rooms)
		ft_exit_error("ERROR : no rooms\n");
	tmp = game->rooms;
	while (tmp)
	{
		if (tmp->name == NULL)
			ft_exit_error("ERROR : missing room name\n");
		tmp = tmp->next;
	}
}
