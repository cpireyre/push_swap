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

void	in_situ_sort(t_ps *ps, t_bool will_print)
{
	while (!autosolve(&ps, will_print, &a_is_ordered))
	{
		if (A_FIRST > A_SECOND && A_FIRST != tab_get_max(ps->a, ps->size_a))
			SA;
		else
			RA;
	}
	while (!autosolve(&ps, will_print, &b_is_ordered))
	{
		if (B_FIRST < B_SECOND && B_FIRST != tab_get_min(ps->b, ps->size_b))
			SB;
		else
			RRB;
	}
}

void	push_all_below_median(t_ps *ps, t_bool will_print)
{
	while (ps->size_b <= ps->size_total / 2)
	{
		if (autosolve(&ps, will_print, &a_is_ordered))
			break ;
		while (A_FIRST > ps->median)
			RA;
		PB;
	}
}

void	splitsort(t_ps *ps, t_bool will_print)
{
	push_all_below_median(ps, will_print);
	in_situ_sort(ps, will_print);
	while (!is_done(ps))
		PA;
}
