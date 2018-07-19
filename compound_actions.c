/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compound_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 09:06:57 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/19 09:26:39 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	place_min_first(t_wheel **to_sort)
{
	t_wheel	*min;
	int		distance;
	int		min_number;
	int		to_sort_size;

	to_sort_size = wheel_init_ranks(to_sort);
	min = wheel_go_to_min(wheel_go_to_head(*to_sort));
	min_number = min->number;
	distance = min->rank - (*to_sort)->rank;
	if (distance > to_sort_size / 2)
	{
		while (!((*to_sort) == min))
		{
			do_and_print(to_sort, 0,  "ra");
			*to_sort = (*to_sort)->prev;
		}
	}
	else
	{
		while (!((*to_sort) == min))
		{
			do_and_print(to_sort, 0,  "rra");
			*to_sort = (*to_sort)->next;
		}
	}
}
