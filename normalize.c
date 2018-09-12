/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 13:54:50 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/12 14:26:06 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	*create_sorted_copy(int *tab, int size)
{
	int	*sorted;

	sorted = ft_memalloc(sizeof(int) * size);
	ft_memcpy((void*)sorted, (void*)(tab), sizeof(int) * size);
	ft_sort_tab(sorted, size);
	return (sorted);
}

int			*calculate_splits(int *sorted, int size, int *nbr_splits)
{
	int	*splits;
	int	i;
	int	pwr;

	*nbr_splits = 0;
	while (size >> *nbr_splits)
		(*nbr_splits)++;
	splits = ft_memalloc(sizeof(int) * *nbr_splits);
	i = 0;
	while (i < *nbr_splits)
	{
		pwr = 1 << i;
		splits[i] = sorted[size - (1 + size / (2 * pwr))];
		i++;
	}
	return (splits);
}

void			normalize_tabs(int **tab, int **sorted, int size)
{
	int		i;
	int		j;
	int		*ptr;

	ptr = *tab;
	i = -1;
	while (++i < size)
	{
		j = 0;
		while (j < size && ptr[j] != (*sorted)[i])
			j++;
		ptr[j] = i + 1;
	}
	i = 0;
	while (++i < size)
		(*sorted)[i] = i + 1;
}
