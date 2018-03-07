/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:40:06 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/07 08:04:08 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_connection	*new_connection(void)
{
	t_connection	*connection;

	if (!(connection = malloc(sizeof(t_connection) * 1)))
		return (NULL);
	connection->name = NULL;
	connection->next = NULL;
	return (connection);
}

void			get_pipe(char *line, t_game *game)
{
	char			**split;

	split = ft_strsplit(line, '-');
	if (!split[0] || !split[1])
		ft_exit_error("ERROR: wrong pipe line format\n");
	if (!room_exists(game, split[0]) || !room_exists(game, split[1]))
		ft_exit_error("ERROR: unknown room in pipe\n");
	create_connection(game, split[0], split[1]);
	create_connection(game, split[1], split[0]);
	free(split[0]);
	free(split[1]);
	free(split);
}

void			create_connection(t_game *game, char *str1, char *str2)
{
	t_connection	*connection;
	t_room			*room;

	room = find_room(game, str1);
	if (connection_in_list(room->connections, str2))
		ft_exit_error("ERROR: duplicate pipe\n");
	connection = new_connection();
	connection->name = ft_strdup(str2);
	room->connections = add_connection_end(room->connections, connection);
}

int				connection_in_list(t_connection *list, char *name)
{
	t_connection	*lst;

	lst = list;
	while (lst)
	{
		if (ft_strcmp(lst->name, name) == 0)
			return (1);
		lst = lst->next;
	}
	return (0);
}

t_connection	*add_connection_end(t_connection *lst, t_connection *item)
{
	t_connection	*list;

	if (lst == NULL)
	{
		lst = item;
		return (lst);
	}
	list = lst;
	while (list->next)
		list = list->next;
	list->next = item;
	item->next = NULL;
	return (lst);
}

t_connection	*add_connection(t_connection *lst, t_connection *item)
{
	item->next = lst;
	lst = item;
	return (lst);
}
