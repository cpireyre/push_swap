/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 15:31:33 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/02 15:33:31 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rra(t_ps *ps, t_bool will_print)
{
	if (ps->size_a >= 2)
		tab_rotate_down(&(ps->a), &(ps->size_a));
	if (will_print)
		print_pattern(ps, "rra");
}

void	rrb(t_ps *ps, t_bool will_print)
{
	if (ps->size_b >= 2)
		tab_rotate_down(&(ps->b), &(ps->size_b));
	if (will_print)
		print_pattern(ps, "rrb");
}

void	rrr(t_ps *ps, t_bool will_print)
{
	rra(ps, will_print);
	rrb(ps, will_print);
}
