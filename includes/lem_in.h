/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 07:11:28 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/05 14:11:11 by cpirlot          ###   ########.fr       */
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

typedef struct	s_pipe
{
	char			*room1;
	char			*room2;
	struct s_pipe	*next;
}				t_pipe;

typedef struct	s_game
{
	int		nb_ants;
	char	*start;
	char	*end;
	t_room	*rooms;
	t_pipe	*pipes;
}				t_game;

/*
** Structures
*/
t_room			*new_room(void);
t_pipe			*new_pipe(void);
t_game			initialize_game(void);
void			free_game(t_game *game);
void			add_room_end(t_game *game, t_room *room);
void			add_pipe_end(t_game *game, t_pipe *pipe);
void			free_game(t_game *game);

/*
** Parsing and error handling
*/
void			read_input(t_game *game);
void			parse_line(char *line, t_game *game);
int				get_ant_nb(char *line);
void			get_room(char *line, t_game *game, int start, int end);
void			get_pipe(char *line, t_game *game);
int				duplicate_room_name(t_game *game);
int				room_exists(t_game	*game, char	*room);

/*
** Playing
*/

#endif
