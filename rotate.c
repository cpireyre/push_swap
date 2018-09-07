/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 15:21:24 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/02 15:23:18 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ra(t_ps *ps, t_bool will_print)
{
	if (ps->size_a >= 2)
		tab_rotate_up(&(ps->a), &(ps->size_a));
	if (will_print)
		print_pattern(ps, "ra");
}

void	rb(t_ps *ps, t_bool will_print)
{
	if (ps->size_b >= 2)
		tab_rotate_up(&(ps->b), &(ps->size_b));
	if (will_print)
		print_pattern(ps, "rb");
}

void	rr(t_ps *ps, t_bool will_print)
{
	ra(ps, will_print);
	rb(ps, will_print);
}
