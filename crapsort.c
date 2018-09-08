#include "header.h"

void	place_min_first(t_ps *ps, t_bool will_print)
{
	int	min;
	int	count;
	t_pattern	spin;

	min = tab_get_min(ps->a, ps->size_a);
	count = 0;
	while (ps->a[count] != min)
		count++;
	spin = ((count * 2) < ps->size_a) ? &ra : &rra;
	while (A_FIRST != min)
	{
		if (A_FIRST == get_next_int(ps->sorted, ps->size_total, min))
			PB;
		if (A_FIRST == min)
			break ;
		spin(ps, will_print);
	}
}

void	crapsort(t_ps *ps, t_bool will_print)
{
	while (ps->size_a)
	{
		place_min_first(ps, will_print);
		PB;
		if (B_FIRST < B_SECOND)
			SB;
	}
	while (ps->size_b)
		PA;
}
