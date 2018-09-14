#include "header.h"

void	two_tapes_quicksort(t_ps *ps, t_byte sort, int cutoff, int size)
{
	int		i;
	int		*tape;
	int		*other_tape;
	t_pattern	push;
	t_pattern	spin;

	if (autosolve(&ps, PRINT, sort ? &a_is_ordered : &b_is_ordered))
		return ;
	push = (sort) ? &pb : &pa;
	spin = (sort) ? &ra : &rb;
	tape = (sort) ? A : B;
	other_tape = (sort) ? B : A;
	cutoff = tape[cutoff];
	i = tablen(tape);
	while (i--)
	{
		push(ps, PRINT);
		if (other_tape[0] < cutoff)
			spin(ps, PRINT);
	}
	two_tapes_quicksort(ps, sort ? 0 : 1, (size + cutoff) / 2, size);
	two_tapes_quicksort(ps, sort ? 0 : 1, (size - cutoff) / 2, size);
}
