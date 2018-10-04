/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 19:32:37 by cpireyre          #+#    #+#             */
/*   Updated: 2018/10/04 10:32:29 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	insertionsort(t_ps *ps, t_bool will_print)
{
	t_pattern	spin;
	int			min;
	int			max;

	PA;
	min = A[0];
	max = A[0];
	while (B[0])
	{
		if (B[0] > max)
		{
			spin = spin_til(ps, min);
			while (A[0] != min)
				spin(ps, will_print);
			max = B[0];
			PA;
		}
		else if (B[0] < min)
		{
			spin = spin_til(ps, min);
			while (A[0] != min)
				spin(ps, will_print);
			min = B[0];
			PA;
		}
		else if (A[0] < B[0] && B[0] < A[1])
		{
			PA;
			SA;
		}
		else
			RA;
	}
	spin = spin_til(ps, 1);
	while (A[0] != 1)
		spin(ps, will_print);
}
