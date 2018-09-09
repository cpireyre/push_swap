#include "header.h"

void	optiswap(t_ps *ps, t_bool will_print)
{
	if (B_FIRST < B_SECOND)
		SS;
	else
		SA;
}

void	optisort(t_ps *ps, t_bool will_print)
{
	while (ps->size_b < ps->size_total / 2)
	{
		if (A_FIRST < ps->splits[2])
			PB;
		else if (A_SECOND >= ps->splits[2] && A_FIRST > A_SECOND)
			optiswap(ps, will_print);
		else
			RA;
	}
}
