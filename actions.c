/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 11:44:36 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/02 15:15:26 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
** pa, sa, ra, rra,
** pb, sb, rb, rrb,
** ss, rr, rrr.
*/

void	pb(t_ps *ps)
{
	int		tmp;

	if (ps->size_a >= 1)
	{
		tmp = (ps->a)[0];
		tab_erase_first(&(ps->a), &(ps->size_a));
		tab_add_first(&(ps->b), &(ps->size_b), tmp);
	}
}

void	pa(t_ps *ps)
{
	int		tmp;

	if (ps->size_b >= 1)
	{
		tmp = (ps->b)[0];
		tab_erase_first(&(ps->b), &(ps->size_b));
		tab_add_first(&(ps->a), &(ps->size_a), tmp);
	}
}

void	sa(t_ps *ps)
{
	if (ps->size_a >= 2)
		ft_swap_int(&((ps->a)[0]), &((ps->a)[1]));
}

void	sb(t_ps *ps)
{
	if (ps->size_b >= 2)
		ft_swap_int(&((ps->b)[0]), &((ps->b)[1]));
}

void	ra(t_ps *ps)
{
	if (ps->size_a >= 2)
		tab_rotate_down(&(ps->a), &(ps->size_a));
}

void	rb(t_ps *ps)
{
	if (ps->size_b >= 2)
		tab_rotate_down(&(ps->b), &(ps->size_b));
}
