#include "../header.h"

/*
**	this pattern is equivalent to:
**	RA; SA; RRA;
**	which one to choose...?
*/

void	swap_second_third(t_ps *ps, t_bool will_print)
{
	PB;
	SA;
	PA;
}

void	swap_first_last(t_ps *ps, t_bool will_print)
{
	RRA;
	SA;
	RA;
}

void	b_swap_second_third(t_ps *ps, t_bool will_print)
{
	RB;
	SB;
	RRB;
}

void	b_swap_first_last(t_ps *ps, t_bool will_print)
{
	RRB;
	SB;
	RB;
}

void	swap_and_down(t_ps *ps, t_bool will_print)
{
	SA;
	RRA;
}

void	b_swap_and_down(t_ps *ps, t_bool will_print)
{
	SB;
	RRB;
}
