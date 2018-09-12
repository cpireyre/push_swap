/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 15:20:10 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/02 15:35:59 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sa(t_ps *ps, t_bool will_print)
{
	if (A[1])
	{
		ft_swap_int(&((A)[0]), &((A)[1]));
		if (will_print)
			print_pattern(ps, "sa");
	}
}

void	sb(t_ps *ps, t_bool will_print)
{
	if (B[1])
	{
		ft_swap_int(&((B)[0]), &((B)[1]));
		if (will_print)
			print_pattern(ps, "sb");
	}
}

void	ss(t_ps *ps, t_bool will_print)
{
	sa(ps, NO_PRINT);
	sb(ps, NO_PRINT);
	if (will_print)
		print_pattern(ps, "ss");
}
