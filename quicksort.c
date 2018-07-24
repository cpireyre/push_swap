/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 08:13:13 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/24 14:44:18 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	find_previous(t_wheel **b)
{
	int		*copy;
	int		i;
	t_wheel	*tmp_prev;
	t_wheel	*tmp_next;

	tmp_prev = (*b)->prev;
	tmp_next = (*b)->next;
	i = 0;
	if ((*b)->number == wheel_go_to_min(*b)->number)
		return ;
	copy = wheel_to_array((*b));
	ft_sort_tab(copy, wheel_count_spokes((*b)));
	while (copy[i] != (*b)->number)
		i++;
	i--;
	while (!(tmp_prev->number == copy[i] || tmp_next->number == copy[i]))
	{
		tmp_prev = tmp_prev->prev;
		tmp_next = tmp_next->next;
	}
	if (tmp_prev->number == copy[i])
		while ((*b)->number != copy[i])
			do_and_print(0, b, "rb");
	else if (tmp_next->number == copy[i])
		while ((*b)->number != copy[i])
			do_and_print(0, b, "rrb");
	free(copy);
}

char	*find_nearest_below(t_wheel *a, t_wheel **b, int median)
{
	t_wheel *tmp_prev;
	t_wheel *tmp_next;
	t_byte	cycle_detector;

	tmp_prev = a->prev;
	tmp_next = a->next;
	cycle_detector = 0;
	if (a->number < median)
	{
		if (b && *b)
			find_previous(b);
		return ("pb");
	}
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

char	*find_nearest_above(t_wheel *a, int cutoff)
{
	t_wheel *tmp_prev;
	t_wheel *tmp_next;
	t_byte	cycle_detector;

	tmp_prev = a->prev;
	tmp_next = a->next;
	cycle_detector = 0;
	if (a->number <= cutoff)
		return ("pb");
	while (1)
	{
		if (tmp_prev->number <= cutoff)
			return ("ra");
		if (tmp_next->number <= cutoff)
			return ("rra");
		tmp_prev = tmp_prev->prev;
		tmp_next = tmp_next->next;
		if (tmp_prev == a || tmp_next == a)
			cycle_detector++;
		if (cycle_detector == 2)
			return (0);
	}
}

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
	int		last_quartile;

	last_quartile = wheel_get_quant(*a, 75);
	while ((action = find_nearest_below(*a, b, median)))
		do_and_print(a, b, action);
	median = wheel_get_quant(*b, 50);
	while ((action = find_nearest_below_again(*b, median)))
		do_and_print(a, b, action);
	while ((action = find_nearest_above(*a, last_quartile)))
		do_and_print(a, b, action);
	while (*a)
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
