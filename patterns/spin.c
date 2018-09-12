/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 13:58:03 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/12 13:58:35 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int			distance(int *tab, int size, int to_find)
{
	int	count;

	count = 0;
	while (tab[count] != to_find && count < size)
		count++;
	return ((count < size) ? count : -1);
}

t_pattern	spin_til(t_ps *ps, int to_find)
{
	t_pattern	spin;

	spin = ((distance(ps->a, ps->size_a, to_find) * 2) < ps->size_a) ? &ra : &rra;
	return (spin);
}

t_pattern	b_spin_til(t_ps *ps, int to_find)
{
	t_pattern	spin;

	spin = ((distance(ps->b, ps->size_b, to_find) * 2) < ps->size_b) ? &rb : &rrb;
	return (spin);
}
