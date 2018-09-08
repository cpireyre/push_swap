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

void	place_min_first(t_ps *ps, t_bool will_print)
{
	t_pattern	spin;
	int		min;

	min = tab_get_min(ps->a, ps->size_a);
	spin = spin_til(ps, min);
	while (A_FIRST != min)
		spin(ps, will_print);
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

void	crapsort(t_ps *ps, t_bool will_print)
{
	t_pattern	last;

	while (!a_is_ordered(ps))
	{
		place_min_first(ps, will_print);
		PB;
		if (ps->size_a <= 3)
		{
			last = find_pattern(ps, a_is_ordered);
			if (last)
				last(ps, will_print);
		}
	}
	while (ps->size_b)
		PA;

