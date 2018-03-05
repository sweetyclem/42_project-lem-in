/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:07:17 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/05 13:37:09 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	get_pipe(char *line, t_game *game)
{
	char	**split;
	t_pipe	*pipe;

	pipe = new_pipe();
	split = ft_strsplit(line, '-');
	if (!split[0] || !split[1])
		ft_exit_error("ERROR: wrong pipe line format\n");
	if (!room_exists(game, split[0]) || !room_exists(game, split[1]))
		ft_exit_error("ERROR: unknown room in pipe");
	pipe->room1 = ft_strdup(split[0]);
	pipe->room2 = ft_strdup(split[1]);
	pipe->next = NULL;
	add_pipe_end(game, pipe);
	free(split[0]);
	free(split[1]);
	free(split);
}

void	add_pipe_end(t_game *game, t_pipe *pipe)
{
	t_pipe	*tmp;

	if (game->pipes == NULL)
	{
		game->pipes = pipe;
		return ;
	}
	tmp = game->pipes;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = pipe;
	pipe->next = NULL;
}
