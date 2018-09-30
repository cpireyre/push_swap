/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:03:47 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/30 18:04:23 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
**	this whole thing is probably deprecated anyway.
*/

t_bool	sorted_up_to_rank(t_ps *ps, t_byte sort, int rank)
{
	int	i;
	int	step;
	int	*tape;

	i = 0;
	tape = sort ? A : B;
	step = sort ? -1 : 1;
	while (tape[++i] && i < rank)
		if (tape[i] != tape[i - 1] + step)
			return (false);
	return (true);
}

void	b_push_up(t_ps *ps, t_bool will_print)
{
	PB;
	RB;
}

void	a_push_up(t_ps *ps, t_bool will_print)
{
	PA;
	RA;
}

void	get_patterns(t_pattern *toby, t_byte sort)
{
	toby[0] = sort ? &pb : &pa;
	toby[1] = sort ? &b_push_up : &a_push_up;
	toby[2] = sort ? &ra : &rb;
	toby[3] = sort ? &rrb : &rra;
	toby[4] = sort ? &rra : &rrb;
}

void	sortab(t_ps *ps, int key, int size, t_bool will_print)
{
	t_pattern	spin;

	spin = find_closest_below(ps, 1, key - 1, true);
	while (entries_in_range(A, 1, key - 1))
	{
		if (1 <= A[0] && A[0] <= key - 1)
		{
			PB;
			spin = find_closest_below(ps, 1, key - 1, true);
		}
		else
			spin(ps, will_print);
	}
	spin = spin_til(ps, key);
	while (A[0] != key)
		spin(ps, will_print);
	PB;
	spin = find_closest_below(ps, key + 1, size, true);
	while (entries_in_range(A, key + 1, size))
	{
		if (key + 1 <= A[0] && A[0] <= size)
		{
			PB;
			spin = find_closest_below(ps, key + 1, size, true);
		}
		else
			spin(ps, will_print);
	}
}

void	sortba(t_ps *ps, int key, int size, t_bool will_print)
{
	t_pattern	spin;

	spin = find_closest_below(ps, key + 1, size, false);
	while (entries_in_range(B, key + 1, size))
	{
		if (key + 1 <= B[0] && B[0] <= size)
		{
			PA;
			spin = find_closest_below(ps, key + 1, size, false);
		}
		else
			spin(ps, will_print);
	}
	spin = b_spin_til(ps, key);
	while (B[0] != key)
		spin(ps, will_print);
	PA;
	spin = find_closest_below(ps, 1, key - 1, false);
	while (entries_in_range(B, 1, key - 1))
	{
		if (1 <= B[0] && B[0] <= key - 1)
		{
			PA;
			spin = find_closest_below(ps, 1, key - 1, false);
		}
		else
			spin(ps, will_print);
	}
}

void	two_tapes_quicksort(t_ps *ps, t_bool will_print)
{
	int	size;

	size = tablen(A);
	sortab(ps, size / 2, size, will_print);
	sortab(ps, 30, 20, will_print);
}
