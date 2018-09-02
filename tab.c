/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 14:18:57 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/02 14:44:35 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

void	tab_rotate_down(int **tab, int *size)
{
	int		tmp;
	int		i;

	if (*size < 2)
		return ;
	else if (*size == 2)
		ft_swap_int(&((*tab)[0]), &((*tab)[1]));
	else
	{
		i = *size;
		while (--i)
		{
			tmp = (*tab)[i];
			(*tab)[i] = (*tab)[i - 1];
			(*tab)[i - 1] = tmp;
		}
	}
}
