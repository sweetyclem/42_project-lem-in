/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 08:00:47 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/07 13:13:29 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_game	game;

	game = initialize_game();
	read_input(&game);
	if (search_graph(&game))
	{
		find_path(&game);
		print_path(&game);
	}
	else
		ft_exit_error("ERROR: no path found");
	free_game(&game);
	return (0);
}
