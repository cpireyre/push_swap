/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:36:08 by cpireyre          #+#    #+#             */
/*   Updated: 2018/08/17 14:12:50 by cpireyre         ###   ########.fr       */
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

void	do_action(t_ps *ps, char *action)
{
	if (ft_strequ(action, "sa") || ft_strequ(action, "ss"))
		do_swap(*ps->a);
	if (ft_strequ(action, "sb") || ft_strequ(action, "ss"))
		do_swap(*ps->b);
	if (ft_strequ(action, "pa"))
		do_push(ps->b, ps->a);
	if (ft_strequ(action, "pb"))
		do_push(ps->a, ps->b);
	if (ft_strequ(action, "ra") || ft_strequ(action, "rr"))
		do_rotate(*ps->a);
	if (ft_strequ(action, "rb") || ft_strequ(action, "rr"))
		do_rotate(*ps->b);
	if (ft_strequ(action, "rra") || ft_strequ(action, "rrr"))
		do_reverse_rotate(*ps->a);
	if (ft_strequ(action, "rrb") || ft_strequ(action, "rrr"))
		do_reverse_rotate(*ps->b);
}

void	do_and_print(t_ps *ps, char *action)
{
	do_action(ps, action);
	ft_putendl(action);
}

t_bool	is_valid_arg(const char *arg)
{
	intmax_t	tmp;

	tmp = ft_atoi(arg);
	if ((intmax_t)INT_MAX < (intmax_t)tmp || (intmax_t)tmp < (intmax_t)INT_MIN)
		return (false);
	if (*arg == '+' || *arg == '-')
		arg++;
	while (*arg)
	{
		if (!ft_isdigit(*arg) && !ft_isblank(*arg))
			return (false);
		arg++;
	}
	return (true);
}

void	do_from_stdin(t_ps *ps, char **line)
{
	if (!is_not_valid_action(*line))
	{
		free(*line);
		free_and_quit(*ps->a, *ps->b);
	}
	else
	{
		do_action(ps, *line);
		free(*line);
	}
}
