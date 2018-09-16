/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 14:08:36 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/16 19:10:38 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

void	smart_push(t_ps *ps, t_bool will_print, int cutoff)
{
	if (A[0] > cutoff / 2)
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
				smart_push(ps, will_print, cutoff);
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

	max = tab_get_max(B);
	min = tab_get_min(B);
	spin = b_spin_til(ps, max);
	while (B[0] != max)
	{
		if (B[0] == max - 1)
			PA;
		else if (B[0] == min)
		{
			PA;
			RA;
		}
		else
			spin(ps, will_print);
	}
	PA;
	if (A[0] == A[1] + 1)
		SA;
}

void	insertionsort(t_ps *ps, t_bool will_print)
{
	t_pattern	aspin;

	while (B[0])
		place_bmax_first(ps, will_print);
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
	while (A[2])
	{
		push_all_below_cutoff(ps, will_print, total - (total / two));
		two *= 2;
	}
	autosolve(&ps, will_print, &a_is_ordered);
	insertionsort(ps, will_print);
}
