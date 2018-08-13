/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 09:50:58 by cpireyre          #+#    #+#             */
/*   Updated: 2018/08/13 12:05:01 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

t_wheel *wheel_go_to_min(t_wheel *spoke)
{
	t_wheel *tmp;
	t_wheel	*min_spoke;

	tmp = spoke;
	min_spoke = spoke;
	spoke = spoke->next;
	while (spoke != tmp)
	{
		if (min_spoke->number > spoke->number)
			min_spoke = spoke;
		spoke = spoke->next;
	}
	return (min_spoke);
}


int		wheel_get_quant(t_wheel *wheel, int cutoff_percent)
{
	size_t	size;
	int		*copy;
	int		quant;

	size = wheel_count_spokes(wheel);
	if (!size)
		return (0);
	copy = wheel_to_array(wheel);
	ft_sort_tab(copy, size);
	size = size * ((float)cutoff_percent / 100);
	quant = copy[size];
	free(copy);
	return (quant);
}

int		wheel_get_avg(t_wheel *wheel)
{
	int	acc;
	int	count;

	count = 1;
	wheel = wheel_go_to_head(wheel);
	acc = wheel->number;
	wheel = wheel->next;
	while (wheel->is_head == false)
	{
		acc += wheel->number;
		count++;
		wheel = wheel->next;
	}
	return (acc / count);
}

t_bool	wheel_has_no_dupes(t_wheel *wheel)
{
	size_t	size;
	int		*copy;
	size_t	i;
	int		tmp;

	size = wheel_count_spokes(wheel);
	if (!size)
		return (0);
	copy = wheel_to_array(wheel);
	ft_sort_tab(copy, size);
	i = 0;
	tmp = *copy;
	while (++i < size)
	{
		if (tmp == copy[i])
			return (false);
		tmp = copy[i];
	}
	free(copy);
	return (true);
}
