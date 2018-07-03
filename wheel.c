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
