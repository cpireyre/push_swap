/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ordered.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 13:56:42 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/14 11:05:49 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_bool	first_three_ok(t_ps *ps)
{
	return (A[1] == A[0] + 1
			&& A[2] == A[1] + 1);
}

t_bool	a_is_ordered(t_ps *ps)
{
	int	max;
	int	min;
	int	i;

	i = 0;
	max = tab_get_max(A);
	min = tab_get_min(A);
	while (A[++i])
		if (A[i - 1] != A[i] - 1)
			return (false);
	return (true);
}

t_bool	b_is_ordered(t_ps *ps)
{
	int	i;

	i = 0;
	while (B[++i])
		if (B[i - 1] != B[i] + 1)
			return (false);
	return (true);
}

t_bool	a_is_increasing(t_ps *ps)
{
	int	i;

	i = -1;
	while (A[++i])
		if (A[i] > A[i + 1])
			return (false);
	return (true);
}

t_bool	b_is_decreasing(t_ps *ps)
{
	int	i;

	i = -1;
	while (B[++i])
		if (B[i] < B[i + 1])
			return (false);
	return (true);
}
