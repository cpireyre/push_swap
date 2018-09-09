#include "header.h"

void	push_half(t_ps *ps, t_bool will_print)
{
	while (ps->size_b < ps->size_total / 2)
		PB;
}

void	dilettantesort(t_ps *ps, t_bool will_print)
{
	push_half(ps, will_print);
}
