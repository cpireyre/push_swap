/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 09:50:58 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/17 08:59:26 by cpireyre         ###   ########.fr       */
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

int		*wheel_to_array(t_wheel *wheel)
{
	size_t	size;
	int		*array;

	size = wheel_count_spokes(wheel);
	array = malloc(sizeof(int) * size);
	wheel = wheel_go_to_head(wheel);
	*array = wheel->number;
	array++;
	wheel = wheel->next;
	while (wheel->is_head == false)
	{
		*array = wheel->number;
		array++;
		wheel = wheel->next;
	}
	return (array - size);
}

int		wheel_get_median(t_wheel *wheel)
{
	size_t	size;
	int		*copy;
	int		median;

	size = wheel_count_spokes(wheel);
	if (!size)
		return (0);
	copy = wheel_to_array(wheel);
	ft_sort_tab(copy, size);
	median = copy[size / 2];
	free(copy);
	return (median);
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
