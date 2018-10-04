/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 19:32:37 by cpireyre          #+#    #+#             */
/*   Updated: 2018/10/04 14:56:33 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_pattern	find_fit(t_ps *ps)
{
	int		index;
	int		len;

	index = 0;
	len = tablen(A);
	if (A[len - 1] < B[0] && B[0] < A[0])
		return (NULL);
	else
	{
		while (!(A[index] < B[0] && B[0] < A[index + 1]))
			index++;
		return (spin_til(ps, A[index]));
	}
}

void		insertionsort(t_ps *ps, t_bool will_print)
{
	t_pattern	spin;
	int			min;
	int			max;

	PA;
	min = A[0];
	max = A[0];
	while (B[0])
	{
		if (B[0] > max)
		{
			spin = spin_til(ps, min);
			while (A[0] != min)
				spin(ps, will_print);
			PA;
			max = A[0];
		}
		else if (B[0] < min)
		{
			spin = spin_til(ps, min);
			while (A[0] != min)
				spin(ps, will_print);
			PA;
			min = A[0];
		}
		else if (A[0] < B[0] && B[0] < A[1])
		{
			PA;
			(B[0] > B[1]) ? SA : SS;
		}
		else
		{
			spin = find_fit(ps);
			if (!spin)
				PA;
			else
				spin(ps, will_print);
		}
	}
	spin = spin_til(ps, 1);
	while (A[0] != 1)
		spin(ps, will_print);
}
