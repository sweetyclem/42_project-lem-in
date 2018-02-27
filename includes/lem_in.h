/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 07:11:28 by cpirlot           #+#    #+#             */
/*   Updated: 2018/02/27 15:03:55 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"

typedef struct	s_room
{
	char			*name;
	struct s_room	*next;
}				t_room;

typedef struct	s_game
{
	int		nb_ants;
	char	*start;
	char	*end;
	t_room	*rooms;
}				t_game;

/*
** Structures
*/
t_room			*new_room(void);
t_game			initialize_game(void);
void			free_game(t_game *game);
void			add_room_end(t_game *game, t_room *room);
void			free_game(t_game *game);

/*
** Parsing and error handling
*/
void			read_input(t_game *game);
void			parse_line(char *line, t_game *game);
int				is_comment(char *str);
void			check_missing_info(t_game *game);

/*
** Playing
*/

#endif
