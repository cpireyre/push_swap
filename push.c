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
