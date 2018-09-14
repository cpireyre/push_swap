/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 14:08:36 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/12 15:00:42 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
/*
**	good candidates for inlining.
*/

t_bool	first_and_next(t_ps *ps)
{
	return (A[1] == A[0] + 1);
}

t_bool	b_first_and_next(t_ps *ps)
{
	return (B[1] == B[0] - 1);
}

/*
**	todo: split these into two patterns
**	and then figure out some way to merge them with rrs and rrrs and sss...
*/

t_bool	entries_below(t_ps *ps, int below)
{
	int	i;

	i = -1;
	while (A[++i])
		if (A[i] < below)
			return (true);
	return (false);
}

void	smart_push(t_ps *ps, t_bool will_print)
{
	int	diff_first;
	int	diff_last;
	int	size_b;

	size_b = tablen(B);
	diff_first = ft_abs(B[0] - A[0]);
	diff_last = ft_abs(B[size_b - 1] - A[0]);
	if (diff_first < diff_last)
		PB;
	else
	{
		PB;
		RB;
	}
}

/*
**	this is where i could use akarasso's trick
**	and push things directly where they belong.
**	it's actually easy early on, because b isn't
**	fully filled out yet, so you don't have to
**	scroll a lot.
*/

void	push_all_below_cutoff(t_ps *ps, t_bool will_print, int cutoff)
{
	while (entries_below(ps, cutoff))
	{
		if (A[0] < cutoff)
		{
			if (B[0])
				smart_push(ps, will_print);
			else
				PB;
		}
		else
			RA;
	}
}

void	place_bmax_first(t_ps *ps, t_bool will_print)
{
	t_pattern	spin;
	int			max;
	int			min;
	t_bool		double_it;

	max = tab_get_max(B);
	min = tab_get_min(B);
	spin = b_spin_til(ps, max);
	while (B[0] != max)
	{
		if ((double_it = (B[0] == min)))
			PA;
		if (!double_it)
			spin(ps, will_print);
		else if (spin == &rb)
			RR;
		else
		{
			RA;
			RRB;
		}
	}
}

void	insertionsort(t_ps *ps, t_bool will_print)
{
	t_pattern	aspin;

	while (B[0])
	{
		place_bmax_first(ps, will_print);
		PA;
	}
	aspin = spin_til(ps, 1);
	while (A[0] != 1)
		aspin(ps, will_print);
}

void	splitsort(t_ps *ps, t_bool will_print)
{
	int	two;
	int	total;

	total = tablen(A) + tablen(B);
	two = 1;
	while (!a_is_ordered(ps))
	{
		push_all_below_cutoff(ps, will_print, total - (total / two));
		two *= 2;
	}
	autosolve(&ps, will_print, &a_is_ordered);
	insertionsort(ps, will_print);
}
