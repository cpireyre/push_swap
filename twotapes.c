#include "header.h"

t_bool	entries_in_range(int *tape, int a, int b)
{
	int	i;

	i = -1;
	while (tape[++i])
		if (a <= tape[i] && tape[i] <= b)
			return (true);
	return (false);
}

void	push_range(t_ps *ps, int a, int b)
{
	while (entries_in_range(A, a, b))
	{
		if (A[0] <= b)
			pb(ps, PRINT);
		else
			ra(ps, PRINT);
	}
	if (B[0] != b)
		rrb(ps, PRINT);
}

/*
**	500 integers, 20 splits: 7488 avg
**	500 integers, 15 splits: 6854 avg
**	500 integers, 10 splits: 6734 avg
**	500 integers, 8 splits: 6988 avg
**	500 integers, 5 splits: 8531 avg
*/

void	two_tapes_quicksort(t_ps *ps)
{
	int	size;
	int	i;
	int	factor;
	int	splits;

	size = tablen(A);
	splits = 12;
	i = size / splits;
	factor = 0;
	while (factor <= splits)
	{
		push_range(ps, (i * factor) + 1, (i * (factor + 1)));
		factor++;
	}
	insertionsort(ps, PRINT);
}
