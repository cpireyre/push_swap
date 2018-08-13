/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 12:02:44 by cpireyre          #+#    #+#             */
/*   Updated: 2018/08/13 12:04:57 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

void	wheel_free_all(t_wheel *spoke)
{
	if (!spoke)
		return ;
	if (spoke->is_head == false)
		spoke = wheel_go_to_head(spoke);
	while (spoke->is_tail == false)
	{
		spoke = spoke->next;
		free(spoke->prev);
	}
	free(spoke);
}

t_wheel	*wheel_delete_spoke(t_wheel *to_delete)
{
	t_wheel	*tmp;

	if (to_delete->next == to_delete)
		tmp = NULL;
	else
		tmp = to_delete->next;
	if (to_delete->is_head == true)
		to_delete->next->is_head = true;
	if (to_delete->is_tail == true)
		to_delete->prev->is_tail = true;
	to_delete->prev->next = to_delete->next;
	to_delete->next->prev = to_delete->prev;
	free(to_delete);
	return (tmp);
}

t_wheel	*wheel_add_tail(t_wheel **oldtail, int input)
{
	t_wheel	*new;

	if (!(new = malloc(sizeof(t_wheel))))
	{
		wheel_free_all(*oldtail);
		exit(1);
	}
	if (*oldtail)
	{
		(*oldtail)->is_tail = false;
		new->prev = *oldtail;
		new->next = wheel_go_to_head(*oldtail);
		new->is_head = false;
		(*oldtail)->next = new;
		new->next->prev = new;
	}
	else
	{
		new->prev = new;
		new->next = new;
		new->is_head = true;
	}
	new->is_tail = true;
	new->number = input;
	return (new);
}

t_wheel	*wheel_add_head(t_wheel **oldhead, int input)
{
	t_wheel	*new;

	if (!(new = malloc(sizeof(t_wheel))))
	{
		wheel_free_all(*oldhead);
		exit(1);
	}
	if (*oldhead)
	{
		(*oldhead)->is_head = false;
		new->is_tail = false;
		(*oldhead)->prev = new;
		new->next = *oldhead;
		new->prev = wheel_go_to_tail(*oldhead);
		new->prev->next = new;
	}
	else
	{
		new->prev = new;
		new->next = new;
		new->is_tail = true;
	}
	new->is_head = true;
	new->number = input;
	return (new);
}

int		*wheel_to_array(t_wheel *wheel)
{
	size_t	size;
	int		*array;

	size = wheel_count_spokes(wheel);
	array = malloc(sizeof(int) * size);
	wheel = wheel_go_to_head(wheel);
	*array = wheel->number;
	array++;
	wheel = wheel->next;
	while (wheel->is_head == false)
	{
		*array = wheel->number;
		array++;
		wheel = wheel->next;
	}
	return (array - size);
}
