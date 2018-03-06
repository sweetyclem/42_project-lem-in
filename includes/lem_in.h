/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 07:11:28 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/06 17:04:43 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"

typedef struct	s_connection
{
	char				*name;
	struct s_connection	*next;
}				t_connection;

typedef struct	s_room
{
	char			*name;
	t_connection	*connections;
	int				visited;
	struct s_room	*next;
}				t_room;

typedef struct	s_game
{
	int				nb_ants;
	char			*start;
	char			*end;
	t_room			*rooms;
	t_connection	*path;
}				t_game;

/*
** Structures
*/
t_game			initialize_game(void);
void			free_game(t_game *game);
void			free_connections(t_connection **connections);
t_room			*new_room(void);
t_room			*find_room(t_game *game, char *name);
void			add_room_end(t_game *game, t_room *room);
t_connection	*new_connection(void);
t_connection	*add_connection_end(t_connection *lst, t_connection *item);
int				connection_in_list(t_connection *list, char *name);

/*
** Parsing and error handling
*/
void			read_input(t_game *game);
void			parse_line(char *line, t_game *game);
int				get_ant_nb(char *line);
void			get_room(char *line, t_game *game, int start, int end);
void			get_pipe(char *line, t_game *game);
void			create_connection(t_game *game, char *str1, char* str2);
int				room_exists(t_game	*game, char	*room);

/*
** Playing
*/
int				search_graph(t_game *game);
t_connection	*queue_connections(t_game *game, t_connection *connections,
				t_connection *queue);
char			*connection_visited(t_game *game, t_connection *connections);
void			find_path(t_game *game);

#endif
