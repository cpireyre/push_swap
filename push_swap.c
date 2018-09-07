/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 10:05:08 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/05 15:45:01 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_next_int(int *sorted, int size, int previous)
{
	int	i;

	i = 0;
	while (i < size - 1 && sorted[i] != previous)
		i++;
	return ((i < size - 1) ? sorted[i + 1] : previous);
}
	
int	get_prev_int(int *sorted, int size, int next)
{
	int	i;

	i = 1;
	while (i < size && sorted[i] != next)
		i++;
	return ((i < size) ? sorted[i - 1] : next);
}

void	find_ordered_pairs(t_ps *ps)
{
	int	min;
	int	max;

	max = tab_get_max(ps->a, ps->size_a);
	min = tab_get_min(ps->a, ps->size_a);
	while (!is_sorted(ps))
	{
/*
**	this sequence swaps the second and third elements
**	and leaves the first one alone
*/
		if (!ps->size_b && try_action(ps, &rra, &is_sorted))
			RRA;
		else if (A_FIRST == min && A_LAST == max)
		{
			RA;
			SA;
			RRA;
		}
/*
**	this sequence swaps the first and last elements
*/
		else if (A_FIRST == max && A_LAST == min)
		{
			RRA;
			SA;
			RA;
		}
		else if (A_FIRST > A_SECOND)
			SA;
		else
			RRA;
	}
}
	

void	push_swap(t_ps *ps)
{
	find_ordered_pairs(ps);
}

int		main(int argc, char **argv)
{
	t_ps	*ps;

	if (argc < 2)
		return (1);
	ps = parse(argc, argv);
	push_swap(ps);
	free_ps(&ps);
	return (0);
}
