/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 09:36:55 by cpireyre          #+#    #+#             */
/*   Updated: 2018/09/05 09:38:38 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		(*get_operation(const char *arg))(t_ps *)
{
	int	i;

	i = -1;
	while (++i < 11)
		if (ft_strequ(arg, g_actions[i].instruction))
			return (g_actions[i].operation);
	return (NULL);
}

void			do_action(t_ps *ps, char **line)
{
	void	(*do_op)(t_ps *);

	do_op = get_operation(*line);
	ft_strdel(line);
	if (do_op)
		do_op(ps);
	else
		quit_push_swap(&ps, MSG_BAD_ACTION);
}
