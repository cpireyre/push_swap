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
	if (ps->size_a >= 2)
		ft_swap_int(&((ps->a)[0]), &((ps->a)[1]));
	if (will_print)
		print_pattern(ps, "sa");
}

void	sb(t_ps *ps, t_bool will_print)
{
	if (ps->size_b >= 2)
		ft_swap_int(&((ps->b)[0]), &((ps->b)[1]));
	if (will_print)
		print_pattern(ps, "sb");
}

void	ss(t_ps *ps, t_bool will_print)
{
	sa(ps, will_print);
	sb(ps, will_print);
}
