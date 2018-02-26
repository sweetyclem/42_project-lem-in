/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 08:13:27 by cpirlot           #+#    #+#             */
/*   Updated: 2018/02/26 13:05:31 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	read_input(t_game *game)
{
	char	*line;

	get_next_line(0, &line);
	if (!ft_isnumber(line))
		ft_exit_error("ERROR : bad format for ant number\n");
	game->nb_ants = ft_atoi(line);
	get_next_line(0, &line);
	if (ft_strcmp(line, "##start") != 0)
		ft_exit_error("ERROR : start line missing\n");
	get_next_line(0, &line);
	
	free(line);
}
