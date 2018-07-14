/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 14:41:04 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/14 09:14:25 by cpireyre         ###   ########.fr       */
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

void	wheel_init_ranks(t_wheel **wheel)
{
	int		current_rank;

	if (!wheel || !*wheel)
		return ;
	current_rank = 0;
	*wheel = wheel_go_to_head(*wheel);
	(*wheel)->rank = current_rank;
	(*wheel) = (*wheel)->next;
	while ((*wheel)->is_head == false)
	{
		current_rank++;
		(*wheel)->rank = current_rank;
		(*wheel) = (*wheel)->next;
	}
}
