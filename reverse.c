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
	if (A[1])
	{
		tab_rotate_down(&(A));
		if (will_print)
			print_pattern(ps, "rra");
	}
}

void	rrb(t_ps *ps, t_bool will_print)
{
	if (B[1])
	{
		tab_rotate_down(&(B));
		if (will_print)
			print_pattern(ps, "rrb");
	}
}

void	rrr(t_ps *ps, t_bool will_print)
{
	rra(ps, NO_PRINT);
	rrb(ps, NO_PRINT);
	if (will_print)
		print_pattern(ps, "rrr");
}
