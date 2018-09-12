/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 14:18:57 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/12 15:08:00 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	tab_erase_first(int **tab)
{
	int		i;

	i = -1;
	while ((*tab)[++i])
		(*tab)[i] = (*tab)[i + 1];
}

/*
**	this one might be glitched out under the new regime.
*/

void	tab_add_first(int **tab, int value)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = (*tab)[0];
	(*tab)[0] = value;
	while ((*tab)[++i])
		ft_swap_int(&tmp, &(*tab)[i]);
	ft_swap_int(&tmp, &(*tab)[i]);
}

void	tab_rotate_down(int **tab)
{
	int		tmp;
	int		i;
	int		size;

	size = tablen(*tab);
	if (size < 2)
		return ;
	else if (size == 2)
		ft_swap_int(&((*tab)[0]), &((*tab)[1]));
	else
	{
		i = size;
		while (--i)
		{
			tmp = (*tab)[i];
			(*tab)[i] = (*tab)[i - 1];
			(*tab)[i - 1] = tmp;
		}
	}
}

void	tab_rotate_up(int **tab)
{
	int		tmp;
	int		i;
	int		size;

	size = tablen(*tab);
	if (size < 2)
		return ;
	else if (size == 2)
		ft_swap_int(&((*tab)[0]), &((*tab)[1]));
	else
	{
		i = -1;
		while (++i < size - 1)
		{
			tmp = (*tab)[i];
			(*tab)[i] = (*tab)[i + 1];
			(*tab)[i + 1] = tmp;
		}
	}
}

/*
**	ft_memcmp returns 0 if the memory areas contain equal values.
**	more or less.
*/

t_bool	is_done(t_ps *ps)
{
	int	i;
	int	size_a;

	if (tablen(B) > 0)
		return (false);
	i = -1;
	size_a = tablen(A);
	while (++i < size_a)
		if (A[i] != i + 1)
			return (false);
	return (true);
}
