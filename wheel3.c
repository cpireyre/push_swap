/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 14:41:04 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/15 09:51:59 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		wheel_init_ranks(t_wheel **wheel)
{
	int		current_rank;

	if (!wheel || !*wheel)
		return (0);
	current_rank = 1;
	*wheel = wheel_go_to_head(*wheel);
	(*wheel)->rank = current_rank;
	(*wheel) = (*wheel)->next;
	while ((*wheel)->is_head == false)
	{
		current_rank++;
		(*wheel)->rank = current_rank;
		(*wheel) = (*wheel)->next;
	}
	return (current_rank);
}
