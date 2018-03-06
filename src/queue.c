/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 09:01:03 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/06 14:46:18 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_queue	*add_queue_end(t_queue *list, t_queue *queue)
{
	t_queue	*tmp;

	if (list == NULL)
	{
		list = queue;
		return (list);
	}
	tmp = list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = queue;
	queue->next = NULL;
	return (list);
}

int	item_in_queue(t_queue *list, char *name)
{
	t_queue	*lst;

	lst = list;
	while (lst)
	{
		if (ft_strcmp(lst->room_name, name) == 0)
			return (1);
		lst = lst->next;
	}
	return (0);
}
