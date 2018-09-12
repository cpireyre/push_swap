/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 15:18:23 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/02 15:18:37 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	pb(t_ps *ps, t_bool will_print)
{
	int		tmp;

	if (A[0])
	{
		tmp = (A)[0];
		tab_erase_first(&(A));
		tab_add_first(&(B), tmp);
		if (will_print)
			print_pattern(ps, "pb");
	}
}

void	pa(t_ps *ps, t_bool will_print)
{
	int		tmp;

	if (B[0])
	{
		tmp = (B)[0];
		tab_erase_first(&(B));
		tab_add_first(&(A), tmp);
		if (will_print)
			print_pattern(ps, "pa");
	}
}
