/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crapsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 14:01:54 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/12 14:05:26 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_bool	finished(t_ps *ps)
{
	t_pattern	solved;

	solved = find_pattern(ps, &is_done);
	if (solved)
		solved(ps, PRINT);
	return (solved ? true : false);
}

/*
**	todo: pb if a_first = next_int(b_min) or prev_int(b_max)?
**	this would keep b congruent and then i could apply patterns
**	to it and sort it that way
*/

void	place_min_first(t_ps *ps, t_bool will_print)
{
	t_pattern	spin;
	int			min;

	min = tab_get_min(A);
	spin = spin_til(ps, min);
	while (A[0] == min)
		spin(ps, will_print);
}

void	crapsort(t_ps *ps, t_bool will_print)
{
	t_pattern	sorta;

	while (!(sorta = find_pattern(ps, a_is_ordered)))
	{
		place_min_first(ps, will_print);
		PB;
	}
	sorta(ps, will_print);
	while (B[0])
		PA;
}
