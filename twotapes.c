/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twotapes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:00:36 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/30 18:09:40 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_bool		entries_in_range(int *tape, int a, int b)
{
	int	i;

	i = -1;
	while (tape[++i])
		if (a <= tape[i] && tape[i] <= b)
			return (true);
	return (false);
}

t_pattern	find_closest_below(t_ps *ps, int a, int b, t_bool atob)
{
	int	min;
	int	dist;
	int	*tape;
	int	tmp;

	tape = atob ? A : B;
	dist = distance(tape, a);
	min = dist;
	tmp = a;
	while (++a <= b)
	{
		dist = distance(tape, a);
		if (dist <= min)
		{
			min = dist;
			tmp = a;
		}
	}
	return (atob ? spin_til(ps, tmp) : b_spin_til(ps, tmp));
}

void		push_range(t_ps *ps, int a, int b, t_bool atob)
{
	t_pattern	push;
	t_pattern	spin;
	int			*tape;

	tape = atob ? A : B;
	spin = find_closest_below(ps, a, b, atob);
	push = atob ? &pb : &pa;
	while (entries_in_range(tape, a, b))
	{
		if (a <= tape[0] && tape[0] <= b)
		{
			push(ps, PRINT);
			spin = find_closest_below(ps, a, b, atob);
		}
		else
			spin(ps, PRINT);
	}
}

void		sortab(t_ps *ps, int splits)
{
	int	size;
	int	i;
	int	factor;

	size = tablen(A);
	i = size / splits;
	factor = 0;
	while (factor <= splits)
	{
		push_range(ps, (i * factor) + 1, (i * (factor + 1)), true);
		factor++;
	}
}

void		sortba(t_ps *ps, int splits)
{
	int	size;
	int	i;

	size = tablen(B);
	i = size / splits;
	while (splits)
	{
		push_range(ps, (i * splits) + 1, (i * (splits + 1)), false);
		splits--;
	}
}

/*
**	500 integers, 20 splits: 7488 avg
**	500 integers, 15 splits: 6854 avg
**	500 integers, 10 splits: 6734 avg
**	500 integers, 8 splits: 6988 avg
**	500 integers, 5 splits: 8531 avg
*/

void		two_tapes_quicksort(t_ps *ps)
{
	sortab(ps, 4);
	sortba(ps, 8);
	sortab(ps, 16);
	while (A[0])
		pb(ps, PRINT);
	insertionsort(ps, PRINT);
}
