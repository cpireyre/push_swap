/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 11:44:36 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/01 13:02:32 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
** pa, sa, ra, rra,
** pb, sb, rb, rrb,
** ss, rr, rrr.
*/

void	tab_erase_first(int **tab, int *size)
{
	int		i;

	if (*size < 1)
		return ;
	i = -1;
	while (++i < (*size - 1))
		(*tab)[i] = (*tab)[i + 1];
	(*size)--;
}

void	tab_add_first(int **tab, int *size, int value)
{
	int		i;
	int		tmp;

	(*size)++;
	i = 0;
	tmp = (*tab)[0];
	(*tab)[0] = value;
	while (++i < (*size))
		ft_swap_int(&tmp, &(*tab)[i]);
}
