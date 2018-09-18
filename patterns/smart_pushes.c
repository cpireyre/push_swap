/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_pushes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 08:48:00 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/18 08:51:40 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_bool	entries_below(t_ps *ps, int below)
{
	int	i;

	i = -1;
	while (A[++i])
		if (A[i] < below)
			return (true);
	return (false);
}

void	smart_push(t_ps *ps, t_bool will_print, int cutoff)
{
	if (A[0] > cutoff / 2)
		PB;
	else
	{
		PB;
		A[0] > cutoff ? RR : RB;
	}
}

void	push_all_below_cutoff(t_ps *ps, t_bool will_print, int cutoff)
{
	while (entries_below(ps, cutoff))
	{
		if (A[0] < cutoff)
		{
			if (B[0])
				smart_push(ps, will_print, cutoff);
			else
				PB;
		}
		else
			RA;
	}
}
