/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intelligentsort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 16:21:25 by cpireyre          #+#    #+#             */
/*   Updated: 2018/10/07 10:24:02 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
**  the idea of this:
**  figure out in advance: which number you're trying to get, as in
**  its position in A, and also where it goes in B;
**  then contrive to rr and rrr so the two stacks line up.
**  kind of no guarantee it'll be faster than anything.
**  incomplete at this time.
*/

void	push_where_appropriate(t_ps *ps, int a, int b, int i)
{
	t_pattern	spin;
	t_bool		will_print;

	will_print = true;
	spin = find_closest_below(ps, a, b, true);
	if (a <= A[0] && A[0] <= b)
	{
		PB;
		if (B[0] < i)
			(A[0] > b || A[0] < a) && (spin == &ra) ? RR : RB;
	}
	else
		spin(ps, PRINT);
}

void	subfilesort(t_ps *ps, t_bool will_print)
{
	int	halfsplits;
	int	i;
	int	a;
	int	b;

	(void)will_print;
	i = tablen(A) / 2;
	halfsplits = i / 11;
	while (A[0])
	{
		a = i - halfsplits;
		b = i + halfsplits;
		while (entries_in_range(A, a, b))
			push_where_appropriate(ps, a, b, i);
		halfsplits += halfsplits;
	}
}
