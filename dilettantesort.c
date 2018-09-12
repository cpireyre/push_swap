/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dilettantesort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 13:52:51 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/12 13:52:59 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	push_half(t_ps *ps, t_bool will_print)
{
	while (ps->size_b < ps->size_total / 2)
		PB;
}

void	dilettantesort(t_ps *ps, t_bool will_print)
{
	push_half(ps, will_print);
}
