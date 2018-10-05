/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 14:08:36 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/30 18:14:39 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
**	this is where i could use akarasso's trick
**	and push things directly where they belong.
**	it's actually easy early on, because b isn't
**	fully filled out yet, so you don't have to
**	scroll a lot.
*/

void	place_bmax_first(t_ps *ps, t_bool will_print)
{
	t_pattern	spin;
	int			max;
	int			min;
	int	len;

	max = tab_get_max(B);
	min = tab_get_min(B);
	spin = b_spin_til(ps, max);
	len = tablen(B);
	while (B[0] != max)
	{
		if (len > 10 && B[0] == max - 1)
			PA;
		else if (len > 10 && B[0] == max - 2)
			PA;
		else if (B[0] == min)
		{
			PA;
			(B[0] != max && B[0] != max - 1 && spin == &rb) ? RR : RA;
			min++;
		}
		else
			spin(ps, will_print);
	}
	PA;
	max = A[0];
	if (tablen(A) >= 2 && A[1] < max)
		(B[0] < B[1]) ? SS : SA;
	if (tablen(A) >= 3 && A[2] < max)
	{
		(B[1] > B[0]) ? RR : RA;
		(B[0] < B[1]) ? SS : SA;
		(B[len - 1] > B[0]) ? RRR : RRA;
	}
}

void	selectionsort(t_ps *ps, t_bool will_print)
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
	if (A[0] == A[1] + 1)
		(B[0] < B[1]) ? SS : SA;
}
