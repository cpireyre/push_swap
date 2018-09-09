#include "header.h"

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
