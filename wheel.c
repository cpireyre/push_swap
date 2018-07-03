/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 09:24:05 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/01 13:37:14 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "wheel.h"

t_wheel	*wheel_go_to_head(t_wheel *ptr)
{
	while (ptr->is_head == false)
		ptr = ptr->prev;
	return (ptr);
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

void	wheel_free_all(t_wheel *spoke)
{
	if (spoke->is_head == false)
		spoke = wheel_go_to_head(spoke);
	while (spoke->is_tail == false)
	{
		spoke = spoke->next;
		free(spoke->prev);
	}
	free(spoke);
}

void	wheel_swap_spokes(t_wheel *a, t_wheel *b)
{
	a->number ^= b->number;
	b->number ^= a->number;
	a->number ^= b->number;
}
