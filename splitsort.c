#include "header.h"

t_bool	first_and_next(t_ps *ps)
{
	return (A_SECOND == get_next_int(ps->sorted, ps->size_total, A_FIRST));
}

t_bool	b_first_and_next(t_ps *ps)
{
	return (B_SECOND == get_prev_int(ps->sorted, ps->size_total, B_FIRST));
}

t_bool	autosolve(t_ps **ps, t_bool will_print, t_checker check)
{
	t_pattern	tmp;

	if (check(*ps))
		return (true);
	tmp = find_pattern(*ps, check);
	if (tmp)
		tmp(*ps, will_print);
	return (tmp ? true : false);
}

/*
**	todo: split these into two patterns
**	and then figure out some way to merge them with rrs and rrrs and sss...
*/

t_bool	entries_below(t_ps *ps, int below)
{
	int	i;

	i = -1;
	while (++i < ps->size_a)
		if (ps->a[i] < below)
			return (true);
	return (false);
}

void	push_all_below_median(t_ps *ps, t_bool will_print)
{
	int	current_median;

	current_median = ps->splits[ps->median];
	while (entries_below(ps, current_median))
	{
		if (A_FIRST < current_median)
			PB;
		else
			RA;
	}
}

void	place_bmax_first(t_ps *ps, t_bool will_print)
{
	t_pattern	spin;
	int		max;

	max = tab_get_max(ps->b, ps->size_b);
	spin = b_spin_til(ps, max);
	while (B_FIRST != max)
		spin(ps, will_print);
}

void	insertionsort(t_ps *ps, t_bool will_print)
{
	while (ps->size_b)
	{
		place_bmax_first(ps, will_print);
		PA;
	}
}

void	splitsort(t_ps *ps, t_bool will_print)
{
	while (ps->size_a >= 4)
	{
		push_all_below_median(ps, will_print);
		*(&ps->median) += 1;
	}
	autosolve(&ps, will_print, &a_is_ordered);
	insertionsort(ps, will_print);
}
