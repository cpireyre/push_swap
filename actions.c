/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 09:36:55 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/05 15:17:08 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_pattern	get_operation(const char *arg)
{
	int	i;

	i = -1;
	while (++i < 11)
		if (ft_strequ(arg, g_actions[i].instruction))
			return (g_actions[i].operation);
	return (NULL);
}

void			do_action(t_ps *ps, char **line, t_bool will_print)
{
	t_pattern do_op;

	do_op = get_operation(*line);
	if (do_op)
		do_op(ps, (will_print) ? PRINT : NO_PRINT);
	else
	{
		ft_strdel(line);
		quit_push_swap(&ps, MSG_BAD_ACTION);
	}
}
