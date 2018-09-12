/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 13:54:38 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/12 14:03:08 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		tab_get_min(int *tab)
{
	int	min;
	int	i;

	i = -1;
	min = tab[0];
	while (tab[++i])
		min = (tab[i] <= min) ? tab[i] : min;
	return (min);
}

int		tab_get_max(int *tab)
{
	int	max;
	int	i;

	i = -1;
	max = tab[0];
	while (tab[++i])
		max = (tab[i] >= max) ? tab[i] : max;
	return (max);
}
