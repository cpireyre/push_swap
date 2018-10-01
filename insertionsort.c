/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 19:32:37 by cpireyre          #+#    #+#             */
/*   Updated: 2018/10/01 19:55:47 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	insertionsort(t_ps *ps, t_bool will_print)
{
	int		dist;
	int		max;

	while (B[0])
	{
		dist = distance(A, B[0] + 1);
		max = tab_get_max(A);
		if (dist == -1)
		{
			if (B[0] > max)
				while (A[0] != max)
					RA;
			PA;
		}
		if (!A[0] || !dist)
			PA;
		else
			RA;
	}
	while (A[0] != 1)
		RRA;
}
