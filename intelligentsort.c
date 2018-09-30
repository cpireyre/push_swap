/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intelligentsort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 16:21:25 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/30 18:14:39 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	push_where_appropriate(t_ps *ps, int a, int b, int i, t_bool will_print)
{
	int			index;
	int			dist;
	t_pattern	spin;

	index = 0;
	while (a <= A[index] && A[index] <= b)
		index++;
	dist = distance(B, A[index] - 1);
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

	i = tablen(A) / 2;
	halfsplits = i / 11;
	while (A[0])
	{
		a = i - halfsplits;
		b = i + halfsplits;
		while (entries_in_range(A, a, b))
			push_where_appropriate(ps, a, b, i, will_print);
		halfsplits += halfsplits;
	}
	selectionsort(ps, will_print);
}
