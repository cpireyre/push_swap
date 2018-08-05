/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 09:55:08 by cpireyre          #+#    #+#             */
/*   Updated: 2018/08/05 10:00:26 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_bool	is_not_valid_action(char *action)
{
	return (ft_strequ(action, "pa")
			|| ft_strequ(action, "ra")
			|| ft_strequ(action, "rra")
			|| ft_strequ(action, "sa")
			|| ft_strequ(action, "pb")
			|| ft_strequ(action, "rb")
			|| ft_strequ(action, "rrb")
			|| ft_strequ(action, "sb")
			|| ft_strequ(action, "ss")
			|| ft_strequ(action, "rr")
			|| ft_strequ(action, "rrr"));
}

void	free_and_quit(t_wheel *a, t_wheel *b)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	if (a)
		wheel_free_all(a);
	if (b)
		wheel_free_all(b);
	exit(EXIT_FAILURE);
}
