/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 08:00:47 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/06 13:58:16 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_game	game;

	game = initialize_game();
	read_input(&game);
	search_graph(&game);
	find_path(&game);
	free_game(&game);
		// ///////////////////////////free path
	return (0);
}
