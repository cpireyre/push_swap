/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:36:28 by cpireyre          #+#    #+#             */
/*   Updated: 2018/08/13 14:36:46 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	wheel_swap_spokes(t_wheel *a, t_wheel *b)
{
	a->number ^= b->number;
	b->number ^= a->number;
	a->number ^= b->number;
}

t_wheel *wheel_go_to_max(t_wheel *spoke)
{
	t_wheel *tmp;
	t_wheel	*max_spoke;

	tmp = spoke;
	max_spoke = spoke;
	spoke = spoke->next;
	while (spoke != tmp)
	{
		if (max_spoke->number < spoke->number)
			max_spoke = spoke;
		spoke = spoke->next;
	}
	return (max_spoke);
}

size_t	wheel_count_spokes(t_wheel *spoke)
{
	size_t	size;
	t_wheel *tmp;

	if (!spoke)
		return (0);
	size = 1;
	tmp = spoke;
	spoke = spoke->next;
	while (spoke != tmp)
	{
		size = size + 1;
		spoke = spoke->next;
	}
	return (size);
}
