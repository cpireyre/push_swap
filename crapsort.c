#include "header.h"

t_pattern	spin_til(t_ps *ps, int to_find)
{
	int	count;
	t_pattern	spin;

	count = 0;
	while (ps->a[count] != to_find)
		count++;
	spin = ((count * 2) < ps->size_a) ? &ra : &rra;
	return (spin);
}

t_bool	finished(t_ps *ps)
{
	t_pattern	solved;

	solved = find_pattern(ps, &is_done);
	if (solved)
		solved(ps, PRINT);
	return (solved ? true : false);
}

void	place_min_first(t_ps *ps, t_bool will_print)
{
	t_pattern	spin;
	int		min;
	int		next;

	min = tab_get_min(ps->a, ps->size_a);
	next = get_next_int(ps->sorted, ps->size_total, min);
	spin = spin_til(ps, min);
	while (A_FIRST != min)
	{
		spin(ps, will_print);
		if (A_FIRST == next)
			PB;
	}
}

t_bool	a_is_ordered(t_ps *ps)
{
	int	i;

	i = -1;
	while (++i < ps->size_a - 1)
		if (ps->a[i + 1] != get_next_int(ps->sorted, ps->size_total, ps->a[i]))
			return (false);
	return (true);
}

t_bool	b_is_ordered(t_ps *ps)
{
	int	i;

	i = -1;
	while (++i < ps->size_b - 1)
		if (ps->b[i + 1] != get_prev_int(ps->sorted, ps->size_total, ps->b[i]))
			return (false);
	return (true);
}

/*
**	todo: pb if a_first = next_int(b_min) or prev_int(b_max)?
**	this would keep b congruent and then i could apply patterns
**	to it and sort it that way
*/


void	crapsort(t_ps *ps, t_bool will_print)
{
	t_pattern sortb;

	while (!a_is_ordered(ps))
	{
		place_min_first(ps, will_print);
		PB;
		if ((sortb = find_pattern(ps, &b_is_ordered)))
			sortb(ps, will_print);
	}
	while (ps->size_b)
		PA;
}
