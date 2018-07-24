/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 08:13:13 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/24 10:00:00 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*sink(t_wheel **a, t_wheel **b, int median)
{
	if ((*a) && (*a)->number > (*a)->next->number && ((*a)->next->number >= median))
		return("sa");
	if ((*b) && (*b)->number < (*b)->next->number)
		return("sb");
	return (0);
}

char	*find_nearest_below(t_wheel *a, int median)
{
	t_wheel *tmp_prev;
	t_wheel *tmp_next;
	t_byte	cycle_detector;

	tmp_prev = a->prev;
	tmp_next = a->next;
	cycle_detector = 0;
	if (a->number < median)
		return ("pb");
	while (1)
	{
		if (tmp_prev->number < median)
			return ("ra");
		if (tmp_next->number < median)
			return ("rra");
		tmp_prev = tmp_prev->prev;
		tmp_next = tmp_next->next;
		if (tmp_prev == a || tmp_next == a)
			cycle_detector++;
		if (cycle_detector == 2)
			return (0);
	}
}

/*
** i'm sorry
*/

char	*find_nearest_below_again(t_wheel *b, int median)
{
	t_wheel *tmp_prev;
	t_wheel *tmp_next;
	t_byte	cycle_detector;

	tmp_prev = b->prev;
	tmp_next = b->next;
	cycle_detector = 0;
	if (b->number < median)
		return ("pa");
	while (1)
	{
		if (tmp_prev->number < median)
			return ("rb");
		if (tmp_next->number < median)
			return ("rrb");
		tmp_prev = tmp_prev->prev;
		tmp_next = tmp_next->next;
		if (tmp_prev == b || tmp_next == b)
			cycle_detector++;
		if (cycle_detector == 2)
			return (0);
	}
}

void	wh_quick_step(t_wheel **a, t_wheel **b, int median)
{
	char	*action;

	while ((action = find_nearest_below(*a, median)))
		do_and_print(a, b, action);
	median = wheel_get_median(*b);
	while ((action = find_nearest_below_again(*b, median)))
		do_and_print(a, b, action);
	while (check_wheel_sortedness(*a) == false)
	{
		place_min_first(a);
		do_and_print(a, b, "pb");
	}
	while (*b)
	{
		place_max_first(b);
		do_and_print(a, b, "pa");
	}
}
