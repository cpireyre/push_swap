/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 13:58:03 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/14 09:30:05 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int			distance(int *tab, int to_find)
{
	int	count;
	int	ret;
	int	len;

	count = 0;
	while (tab[count] && tab[count] != to_find)
		count++;
	len = tablen(tab);
	ret = ((count * 2) < len) ? count : -1 * (len - count);
	return (ret);
}

t_pattern	spin_til(t_ps *ps, int to_find)
{
	t_pattern	spin;

	spin = distance(A, to_find) > 0 ? &ra : &rra;
	return (spin);
}

t_pattern	b_spin_til(t_ps *ps, int to_find)
{
	t_pattern	spin;

	spin = distance(B, to_find) > 0 ? &rb : &rrb;
	return (spin);
}

void		b_actually_spin(t_ps *ps, t_bool will_print, int to_find)
{
	t_pattern	spin;

	spin = b_spin_til(ps, to_find);
	while (B[0] != to_find)
		spin(ps, will_print);
}
