#include "header.h"

t_bool	finished(t_ps *ps)
{
	t_pattern	solved;

	solved = find_pattern(ps, &is_done);
	if (solved)
		solved(ps, PRINT);
	return (solved ? true : false);
}

/*
**	todo: pb if a_first = next_int(b_min) or prev_int(b_max)?
**	this would keep b congruent and then i could apply patterns
**	to it and sort it that way
*/

void	place_min_first(t_ps *ps, t_bool will_print)
{
	t_pattern	spin;
	int		min;

	min = tab_get_min(ps->a, ps->size_a);
	spin = spin_til(ps, min);
	while (A_FIRST != min)
		spin(ps, will_print);
}

void	crapsort(t_ps *ps, t_bool will_print)
{
	t_pattern	sorta;

	while (!(sorta = find_pattern(ps, a_is_ordered)))
	{
		place_min_first(ps, will_print);
		PB;
	}
	sorta(ps, will_print);
	while (ps->size_b)
		PA;
}
