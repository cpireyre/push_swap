#include "header.h"

void	subfilesort(t_ps *ps, t_bool will_print)
{
	int	halfsplits;
	int	i;
	int	a;
	int	b;
	t_pattern	spin;

	i = tablen(A) / 2;
	halfsplits = 20;
	while (A[0])
	{
		a = i - halfsplits;
		b = i + halfsplits;
		spin = find_closest_below(ps, a, b, true);
		while (entries_in_range(A, a, b))
		{
			if (a <= A[0] && A[0] <= b)
			{
				PB;
				if (B[0] < i)
					(A[0] > b || A[0] < a)
					&& (spin == &ra) ? RR : RB;
				spin = find_closest_below(ps, a, b, true);
			}
			else
				spin(ps, PRINT);
		}
		halfsplits += halfsplits;
	}
	insertionsort(ps, will_print);
}
