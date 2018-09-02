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

void	rra(t_ps *ps)
{
	if (ps->size_a >= 2)
		tab_rotate_up(&(ps->a), &(ps->size_a));
}

void	rrb(t_ps *ps)
{
	if (ps->size_b >= 2)
		tab_rotate_up(&(ps->b), &(ps->size_b));
}

void	rrr(t_ps *ps)
{
	rra(ps);
	rrb(ps);
}
