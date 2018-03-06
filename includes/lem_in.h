/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 07:11:28 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/06 14:45:11 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"

typedef struct	s_connection
{
	char				*name;
	struct s_connection	*next;
}				t_connect;

typedef struct	s_room
{
	char			*name;
	t_connect		*connections;
	int				visited;
	struct s_room	*next;
}				t_room;

typedef struct	s_queue
{
	char			*room_name;
	struct s_queue	*next;
}				t_queue;

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
t_connect		*new_connection(void);
t_queue			*new_queue(void);
t_game			initialize_game(void);
void			free_game(t_game *game);
void			add_room_end(t_game *game, t_room *room);
void			add_connection_end(t_room *room, char *connection_name);
t_queue			*add_queue_end(t_queue *list, t_queue *queue);
t_room			*find_room(t_game *game, char *name);
int				item_in_queue(t_queue *list, char *name);

/*
** Parsing and error handling
*/
void			read_input(t_game *game);
void			parse_line(char *line, t_game *game);
int				get_ant_nb(char *line);
void			get_room(char *line, t_game *game, int start, int end);
void			get_pipe(char *line, t_game *game);
int				room_exists(t_game	*game, char	*room);

/*
** Playing
*/
int				search_graph(t_game *game);
t_queue			*queue_connections(t_game *game, t_connect *connec,
				t_queue *queue_list);
char			*get_connected_visited(t_game *game, t_connect *connections);
void			find_path(t_game *game);

#endif
