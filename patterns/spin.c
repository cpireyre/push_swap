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

int			distance(int *tab, int to_find)
{
	int	count;

	count = 0;
	while (tab[count] && tab[count] != to_find)
		count++;
	return (tab[count] ? count : -1);
}

t_pattern	spin_til(t_ps *ps, int to_find)
{
	t_pattern	spin;

	spin = ((distance(A, to_find) * 2) < tablen(A)) ? &ra : &rra;
	return (spin);
}

t_pattern	b_spin_til(t_ps *ps, int to_find)
{
	t_pattern	spin;

	spin = ((distance(B, to_find) * 2) < tablen(B)) ? &rb : &rrb;
	return (spin);
}
