#include "header.h"

t_bool	sorted_up_to_rank(t_ps *ps, t_byte sort, int rank)
{
	int	i;
	int	step;
	int	*tape;

	i = 0;
	tape = sort ? A : B;
	step = sort ? -1 : 1;
	while (tape[++i] && i < rank)
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

void	get_patterns(t_pattern *toby, t_byte sort)
{
	toby[0] = sort ? &pb : &pa;
	toby[1] = sort ? &b_push_up : &a_push_up;
	toby[2] = sort ? &ra : &rb;
	toby[3] = sort ? &rrb : &rra;
	toby[4] = sort ? &rra : &rrb;
}

void	two_tapes_quicksort(t_ps *ps, int cutoff, int size, t_byte sort)
{
	int	i;
	int	*tape;
	t_pattern	toby[5];
	
	tape = sort ? A : B;
	if (sorted_up_to_rank(ps, sort, size))
		return ;
	get_patterns(toby, sort);
	i = size;
	while (i--)
	{
		if (tape[0] > cutoff)
			toby[0](ps, PRINT);
		else if (tape[0] == cutoff)
			toby[1](ps, PRINT);
		else
			toby[2](ps, PRINT);
	}
	toby[3](ps, PRINT);
	while (size--)
	{
		if (tape[0] < cutoff)
			toby[0](ps, PRINT);
		else
			toby[4](ps, PRINT);
	}
	two_tapes_quicksort(ps, cutoff / 2, size / 2, sort ? 0 : 1);
}
