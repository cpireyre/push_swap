/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twotapes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:00:36 by cpireyre          #+#    #+#             */
/*   Updated: 2018/10/07 10:16:28 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_bool		entries_in_range(int *tape, int a, int b)
{
	int	i;

	i = -1;
	while (tape[++i])
		if (a <= tape[i] && tape[i] <= b)
			return (true);
	return (false);
}

t_pattern	find_closest_below(t_ps *ps, int a, int b, t_bool spin_a)
{
	int	min;
	int	dist;
	int	*tape;
	int	tmp;

	tape = spin_a ? A : B;
	dist = distance(tape, a);
	min = dist;
	tmp = a;
	while (++a <= b)
	{
		dist = distance(tape, a);
		if (dist <= min)
		{
			min = dist;
			tmp = a;
		}
	}
	return (spin_a ? spin_til(ps, tmp) : b_spin_til(ps, tmp));
}

void		push_range(t_ps *ps, int a, int b, t_bool atob)
{
	t_pattern	push;
	t_pattern	spin;
	int			*tape;

	tape = atob ? A : B;
	spin = find_closest_below(ps, a, b, atob);
	push = atob ? &pb : &pa;
	while (entries_in_range(tape, a, b))
	{
		if (a <= tape[0] && tape[0] <= b)
		{
			push(ps, PRINT);
			spin = find_closest_below(ps, a, b, atob);
		}
		else
			spin(ps, PRINT);
	}
}
