/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:36:08 by cpireyre          #+#    #+#             */
/*   Updated: 2018/07/14 09:13:28 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_bool	check_wheel_sortedness(t_wheel *wheel)
{
	if (wheel->is_head == false)
		wheel = wheel_go_to_head(wheel);
	while (wheel->is_tail == false)
	{
		if (wheel->number > wheel->next->number)
			return (false);
		wheel = wheel->next;
	}
	return (true);
}

/*
 ** sa, sb, ss. pa, pb. ra, rb, rr. rra, rrb, rrr.
 */

void	do_action(t_wheel **a, t_wheel **b, char *action)
{
	if (action[0] == 's')
	{
		if (action[1] == 'a' || action[1] == 's')
			do_swap(*a);
		if (action[1] == 'b' || action[1] == 's')
			do_swap(*b);
	}
	else if (ft_strequ(action, "pa"))
		do_push(b, a);
	else if (ft_strequ(action, "pb"))
		do_push(a, b);
	else if (action[0] == 'r' && action[2] == 0)
	{
		if (action[1] == 'a' || action[1] == 'r')
			do_rotate(*a);
		if (action[1] == 'b' || action[1] == 'r')
			do_rotate(*b);
	}
	else if (action[0] == 'r' && action[1] == 'r')
	{
		if (action[2] == 'a' || action[2] == 'r')
			do_reverse_rotate(*a);
		if (action[2] == 'b' || action[2] == 'r')
			do_reverse_rotate(*b);
	}
}
