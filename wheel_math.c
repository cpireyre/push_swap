/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 09:50:58 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/15 12:07:24 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		wheel_get_median(t_wheel *wheel)
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
