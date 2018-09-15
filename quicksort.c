#include "header.h"

t_bool	sorted_up_to_cutoff(t_ps *ps, t_byte sort, int cutoff)
{
	int	i;
	int	step;
	int	*tape;

	i = 0;
	tape = sort ? A : B;
	step = sort ? -1 : 1;
	while (tape[++i] && i < cutoff)
		if (tape[i] != tape[i - 1] + step)
			return (false);
	return (true);
}

void	b_push_up(t_ps *ps, t_bool will_print)
{
	PB;
	RB;
}

void	a_push_up(t_ps *ps, t_bool will_print)
{
	PA;
	RA;
}

void	two_tapes_quicksort(t_ps *ps, int cutoff, int size, t_byte sort)
{
	int	i;
	int	*tape;
	t_pattern	push;
	t_pattern	push_up;
	t_pattern	spin;
	t_pattern	rspin;
	
	tape = sort ? A : B;
	push = sort ? &pb : &pa;
	push_up = sort ? &b_push_up : &a_push_up;
	spin = sort ? &ra : &rb;
	rspin = sort ? &rrb : &rra;
	i = size;
	while (i--)
	{
		if (tape[0] > cutoff)
			push(ps, PRINT);
		else if (tape[0] == cutoff)
			push_up(ps, PRINT);
		else
			spin(ps, PRINT);
	}
	rspin(ps, PRINT);
}
