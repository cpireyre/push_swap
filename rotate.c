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
	if (A[1])
	{
		tab_rotate_up(&(A));
		if (will_print)
			print_pattern(ps, "ra");
	}
}

void	rb(t_ps *ps, t_bool will_print)
{
	if (B[1])
	{
		tab_rotate_up(&(B));
		if (will_print)
			print_pattern(ps, "rb");
	}
}

void	rr(t_ps *ps, t_bool will_print)
{
	ra(ps, NO_PRINT);
	rb(ps, NO_PRINT);
	if (will_print)
		print_pattern(ps, "rr");
}
