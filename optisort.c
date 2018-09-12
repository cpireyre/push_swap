/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 13:53:03 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/12 13:54:01 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	optiswap(t_ps *ps, t_bool will_print)
{
	if (B_FIRST < B_SECOND)
		SS;
	else
		SA;
}

void	optisort(t_ps *ps, t_bool will_print)
{
	while (ps->size_b < ps->size_total / 2)
	{
		if (A_FIRST < ps->splits[2])
			PB;
		else if (A_SECOND >= ps->splits[2] && A_FIRST > A_SECOND)
			optiswap(ps, will_print);
		else
			RA;
	}
}
